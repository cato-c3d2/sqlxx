/*!
 * @file select-closure.class.h++
 */

#ifndef SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX
#define SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX

#include <sql++/identifier/column-identifier.class.h++>

#include <initializer_list>
#include <string>
#include <vector>

namespace sqlxx
{
inline namespace closure
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief "SELECT 句" の文法クラス
     */
    class SelectClosure
    {
    public:
        /*!
         * @brief "カラム指定のリスト" の型
         */
        using ColumnListType = std::vector<identifier::ColumnIdentifier>;

        /*!
         * @brief デフォルトコンストラクタ
         */
        SelectClosure();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] column_list "カラム指定" の文法オブジェクトの初期化リスト
         */
        SelectClosure(
            std::initializer_list<identifier::ColumnIdentifier> column_list);

        /*!
         * @brief "カラム指定のリスト" を設定する
         *
         * @param[in] column_list "カラム指定" の文法オブジェクトの初期化リスト
         *
         * @return このオブジェクトの参照
         */
        auto column_list(
            std::initializer_list<identifier::ColumnIdentifier> column_list)
            -> SelectClosure &;

        /*!
         * @brief このオブジェクトが空か判定する
         *
         * @return このオブジェクトが空の場合は @c true を,
         *         そうではない場合は @c false を返却する
         */
        auto empty() const -> bool;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        /*!
         * @brief "カラム指定のリスト"
         */
        ColumnListType _column_list;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out            出力ストリーム
     * @param[in] select_closure "SELECT 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, SelectClosure const select_closure)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    SelectClosure::SelectClosure() : _column_list()
    {}

    SelectClosure::SelectClosure(
        std::initializer_list<identifier::ColumnIdentifier> column_list)
        : _column_list(column_list)
    {}

    auto SelectClosure::column_list(
        std::initializer_list<identifier::ColumnIdentifier> column_list)
        -> SelectClosure &
    {
        this->_column_list = column_list;
        return *this;
    }

    auto SelectClosure::empty() const -> bool
    {
        // この SELECT 句が保持するカラムオブジェクトが 0 個の場合,
        // この SELECT 句 を空とみなす.
        if (this->_column_list.empty()) {
            return true;
        }

        // この SELECT 句が保持するカラムオブジェクトがいずれも空の場合,
        // この SELECT 句を空とみなす.
        return std::all_of(
            std::begin(this->_column_list),
            std::end(this->_column_list),
            [](auto && column) {
                return column.empty();
            });
    }

    auto SelectClosure::to_string() const -> std::string
    {
        if (this->_column_list.empty()) {
            return "";
        }
        std::string column_list = "";
        std::string delimiter   = "";
        for (auto && column : this->_column_list) {
            if (column.empty()) {
                continue;
            }
            column_list += delimiter + column.to_string();
            delimiter = ", ";
        }
        if (column_list.empty()) {
            return "";
        }
        return "SELECT " + column_list;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, SelectClosure const select_closure)
        -> std::ostream &
    {
        out << select_closure.to_string();
        return out;
    }
} // namespace closure
} // namespace sqlxx

#endif // SQLXX__CLOSURE__SELECT_CLOSURE_CLASS_HXX
