/*!
 * @file table.class.h++
 */

#ifndef SQLXX__SPECIFICATION__TABLE_CLASS_HXX
#define SQLXX__SPECIFICATION__TABLE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

namespace sqlxx::specification
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
        using AliasNameType = std::string;

        /*!
         * @brief デフォルトコンストラクタ
         */
        Table();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] table_name テーブル名
         * @param[in] alias_name エイリアス名
         */
        Table(TableNameType table_name, AliasNameType alias_name = "");

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] table_name テーブル名
         *
         * @return このオブジェクトの参照
         */
        auto table_name(TableNameType table_name) -> Table &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         */
        auto alias_name(AliasNameType alias_name) -> Table &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        TableNameType _table_name;
        AliasNameType _alias_name;
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

#include <sql++/specification/naming-rule.class.h++>

namespace sqlxx::specification
{
    Table::Table() : _table_name(), _alias_name()
    {}

    Table::Table(TableNameType table_name, AliasNameType alias_name)
        : _table_name(table_name), _alias_name(alias_name)
    {}

    auto Table::table_name(TableNameType table_name) -> Table &
    {
        this->_table_name = table_name;
        return *this;
    }

    auto Table::alias_name(AliasNameType alias_name) -> Table &
    {
        this->_alias_name = alias_name;
        return *this;
    }

    auto Table::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_table_name)) {
            return "";
        }
        std::string text = this->_table_name;
        if (NamingRule::is_legal(this->_alias_name)) {
            text += " AS " + this->_alias_name;
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

#endif // SQLXX__SPECIFICATION__TABLE_CLASS_HXX
