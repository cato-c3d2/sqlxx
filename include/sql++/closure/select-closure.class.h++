/*!
 * @file select-closure.class.h++
 */

#ifndef SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX
#define SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/specification/column.class.h++>

#include <initializer_list>
#include <string>
#include <vector>

namespace sqlxx::closure
{
    /*!
     * @brief "SELECT 句" の文法クラス
     */
    class SelectClosure
    {
    public:
        /*! @brief "カラム指定のリスト" の型 */
        using ColumnListType = std::vector<specification::Column>;

        /*!
         * @brief デフォルトコンストラクタ
         */
        SelectClosure();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] column_list "カラム指定" の文法オブジェクトの初期化リスト
         */
        SelectClosure(std::initializer_list<specification::Column> column_list);

        /*!
         * @brief "カラム指定のリスト" を設定する
         *
         * @param[in] column_list "カラム指定" の文法オブジェクトの初期化リスト
         *
         * @return このオブジェクトの参照
         */
        auto
        column_list(std::initializer_list<specification::Column> column_list)
            -> SelectClosure &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        ColumnListType _column_list;
    };

    /**
     * @brief ストリーム出力演算
     *
     * @param[in] out            出力ストリーム
     * @param[in] select_closure "SELECT 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, SelectClosure const select_closure)
        -> std::ostream &;
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

namespace sqlxx::closure
{
    SelectClosure::SelectClosure() : _column_list()
    {}

    SelectClosure::SelectClosure(
        std::initializer_list<specification::Column> column_list)
        : _column_list(column_list)
    {}

    auto SelectClosure::column_list(
        std::initializer_list<specification::Column> column_list)
        -> SelectClosure &
    {
        this->_column_list = column_list;
        return *this;
    }

    auto SelectClosure::to_string() const -> std::string
    {
        if (this->_column_list.empty()) {
            return "";
        }
        std::string column_list = "";
        std::string delimiter   = "";
        for (auto && column : this->_column_list) {
            auto const column_specification = column.to_string();
            if (column_specification.empty()) {
                continue;
            }
            column_list += delimiter + column_specification;
            delimiter = ", ";
        }
        if (column_list.empty()) {
            return "";
        }
        return "SELECT " + column_list;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, SelectClosure const select_closure)
        -> std::ostream &
    {
        out << select_closure.to_string();
        return out;
    }
}

#endif // SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX
