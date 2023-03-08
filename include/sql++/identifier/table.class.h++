/*!
 * @file table.class.h++
 */

#ifndef SQLXX__IDENTIFIER__TABLE_CLASS_HXX
#define SQLXX__IDENTIFIER__TABLE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/closure/as-closure.class.h++>

#include <string>

namespace sqlxx::identifier
{
    /*!
     * @brief テーブル指定の文法クラス
     */
    class Table
    {
    public:
        /*! @brief テーブル名の型 */
        using TableNameType = std::string;

        /*! @brief エイリアス名の型 */
        using AliasNameType = closure::AsClosure::AliasNameType;

        /*!
         * @brief デフォルトコンストラクタ
         */
        Table();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table_name テーブル名
         * @param[in] as_closure "AS 句" の文法オブジェクト
         */
        Table(TableNameType table_name, closure::AsClosure as_closure = {});

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table_name テーブル名
         * @param[in] alias_name エイリアス名
         */
        Table(TableNameType table_name, AliasNameType alias_name);

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] table_name テーブル名
         *
         * @return このオブジェクトの参照
         */
        auto table_name(TableNameType table_name) -> Table &;

        /*!
         * @brief "AS 句" を設定する
         *
         * @param[in] as_closure "AS 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto as(closure::AsClosure as_closure) -> Table &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         */
        auto alias_name(AliasNameType alias_name) -> Table &;

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
        TableNameType      _table_name;
        closure::AsClosure _as_closure;
    };

    /**
     * @brief ストリーム出力演算
     *
     * @param[in] out   出力ストリーム
     * @param[in] table テーブル指定の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, Table const table) -> std::ostream &;
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx::identifier
{
    Table::Table() : _table_name(), _as_closure()
    {}

    Table::Table(TableNameType table_name, closure::AsClosure as_closure)
        : _table_name(table_name), _as_closure(as_closure)
    {}

    Table::Table(TableNameType table_name, AliasNameType alias_name)
        : _table_name(table_name)
        , _as_closure(closure::AsClosure { alias_name })
    {}

    auto Table::table_name(TableNameType table_name) -> Table &
    {
        this->_table_name = table_name;
        return *this;
    }

    auto Table::as(closure::AsClosure as_closure) -> Table &
    {
        this->_as_closure = as_closure;
        return *this;
    }

    auto Table::alias_name(AliasNameType alias_name) -> Table &
    {
        this->_as_closure.alias_name(alias_name);
        return *this;
    }

    auto Table::empty() const -> bool
    {
        return ! NamingRule::is_legal(this->_table_name);
    }

    auto Table::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_table_name)) {
            return "";
        }
        std::string text = this->_table_name;
        if (NamingRule::is_legal(this->_as_closure.alias_name())) {
            text += " " + this->_as_closure.to_string();
        }
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, Table const table) -> std::ostream &
    {
        out << table.to_string();
        return out;
    }
}

#endif // SQLXX__IDENTIFIER__TABLE_CLASS_HXX
