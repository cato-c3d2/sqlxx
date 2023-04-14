/*!
 * @file select-statement.class.h++
 */

#ifndef SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX
#define SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/closure/from-closure.class.h++>
#include <sql++/closure/select-closure.class.h++>

#include <initializer_list>
#include <string>

namespace sqlxx
{
inline namespace statement
{
    /*!
     * @brief "SELECT 文" の文法クラス
     */
    class SelectStatement
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        SelectStatement();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] select_closure "SELECT 句" の文法オブジェクト
         * @param[in] from_closure   "FROM 句" の文法オブジェクト
         */
        SelectStatement(
            closure::SelectClosure select_closure,
            closure::FromClosure   from_closure = {});

        /*!
         * @brief "SELECT 句" を設定する
         *
         * @param[in] select_closure "SELECT 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto select(closure::SelectClosure select_closure) -> SelectStatement &;

        /*!
         * @brief "FROM 句" を設定する
         *
         * @param[in] from_closure "FROM 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto from(closure::FromClosure from_closure) -> SelectStatement &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        closure::SelectClosure _select_closure;
        closure::FromClosure   _from_closure;
    };

    /**
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] select_statement "SELECT 文" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, SelectStatement const select_statement)
        -> std::ostream &;
}
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

namespace sqlxx
{
inline namespace statement
{
    SelectStatement::SelectStatement() : _select_closure(), _from_closure()
    {}

    SelectStatement::SelectStatement(
        closure::SelectClosure select_closure,
        closure::FromClosure   from_closure)
        : _select_closure(select_closure), _from_closure(from_closure)
    {}

    auto SelectStatement::select(closure::SelectClosure select_closure)
        -> SelectStatement &
    {
        this->_select_closure = select_closure;
        return *this;
    }

    auto SelectStatement::from(closure::FromClosure from_closure)
        -> SelectStatement &
    {
        this->_from_closure = from_closure;
        return *this;
    }

    auto SelectStatement::to_string() const -> std::string
    {
        std::vector<std::string> closures;

        if (this->_select_closure.empty()) {
            return "";
        }
        closures.push_back(this->_select_closure.to_string());

        if (this->_from_closure.empty()) {
            return "";
        }
        closures.push_back(this->_from_closure.to_string());

        std::string text      = "";
        std::string delimiter = "";
        for (auto && closure : closures) {
            text += delimiter + closure;
            delimiter = " ";
        }
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, SelectStatement const select_statement)
        -> std::ostream &
    {
        out << select_statement.to_string();
        return out;
    }
}
}

#endif // SQLXX__STATEMENT__SELECT_STATEMENT_CLASS_HXX
