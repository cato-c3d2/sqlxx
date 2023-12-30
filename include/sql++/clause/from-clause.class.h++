/*!
 * @file from-clause.class.h++
 */

#ifndef SQLXX__CLAUSE__FROM_CLAUSE_CLASS_HXX
#define SQLXX__CLAUSE__FROM_CLAUSE_CLASS_HXX

#include <string>

#include <sql++/identifier/table-identifier.class.h++>

namespace sqlxx
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief "FROM 句" の文法クラス
     */
    class FromClause
    {
    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        FromClause();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         */
        FromClause(identifier::TableIdentifier table);

        /*!
         * @brief "テーブル指定" を設定する
         *
         * @param[in] table "テーブル指定" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto table(identifier::TableIdentifier table) -> FromClause &;

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
     * @param[in] from_clause  "FROM 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, FromClause const from_clause)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    FromClause::FromClause() : _table()
    {}

    FromClause::FromClause(identifier::TableIdentifier table) : _table(table)
    {}

    auto FromClause::table(identifier::TableIdentifier table) -> FromClause &
    {
        this->_table = table;
        return *this;
    }

    auto FromClause::empty() const -> bool
    {
        return this->_table.empty();
    }

    auto FromClause::to_string() const -> std::string
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

    auto operator<<(std::ostream & out, FromClause const from_clause)
        -> std::ostream &
    {
        out << from_clause.to_string();
        return out;
    }
} // namespace clause
} // namespace sqlxx

#endif // SQLXX__CLAUSE__FROM_CLAUSE_CLASS_HXX
