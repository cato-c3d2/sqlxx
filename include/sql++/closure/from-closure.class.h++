/*!
 * @file from-closure.class.h++
 */

#ifndef SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX
#define SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX

#include <sql++/identifier/table-identifier.class.h++>

#include <string>

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
     * @brief "FROM 句" の文法クラス
     */
    class FromClosure
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        FromClosure();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         */
        FromClosure(identifier::TableIdentifier table);

        /*!
         * @brief "テーブル指定" を設定する
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto table(identifier::TableIdentifier table) -> FromClosure &;

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
         * @brief "テーブル指定"
         */
        identifier::TableIdentifier _table;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out          出力ストリーム
     * @param[in] from_closure "FROM 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, FromClosure const from_closure)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    FromClosure::FromClosure() : _table()
    {}

    FromClosure::FromClosure(identifier::TableIdentifier table) : _table(table)
    {}

    auto FromClosure::table(identifier::TableIdentifier table) -> FromClosure &
    {
        this->_table = table;
        return *this;
    }

    auto FromClosure::empty() const -> bool
    {
        return this->_table.empty();
    }

    auto FromClosure::to_string() const -> std::string
    {
        if (this->_table.empty()) {
            return "";
        }
        return "FROM " + this->_table.to_string();
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, FromClosure const from_closure)
        -> std::ostream &
    {
        out << from_closure.to_string();
        return out;
    }
} // namespace closure
} // namespace sqlxx

#endif // SQLXX__CLOSURE__FROM_CLOSURE_CLASS_HXX
