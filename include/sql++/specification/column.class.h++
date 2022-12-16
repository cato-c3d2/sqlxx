/*!
 * @file column.class.h++
 */

#ifndef SQLXX__SPECIFICATION__COLUMN_CLASS_HXX
#define SQLXX__SPECIFICATION__COLUMN_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

namespace sqlxx::specification
{
    /*!
     * @brief カラム指定の文法クラス
     */
    class Column
    {
    public:
        /*! @brief カラム名の型 */
        using ColumnNameType = std::string;

        /*! @brief エイリアス名の型 */
        using AliasNameType = std::string;

        /*!
         * @brief デフォルトコンストラクタ
         */
        Column();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] column_name カラム名
         * @param[in] alias_name  エイリアス名
         */
        Column(ColumnNameType column_name, AliasNameType alias_name = "");

        /*!
         * @brief カラム名を設定する
         *
         * @param[in] column_name カラム名
         *
         * @return このオブジェクトの参照
         */
        auto column_name(ColumnNameType column_name) -> Column &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         */
        auto alias_name(AliasNameType alias_name) -> Column &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

    private:
        ColumnNameType _column_name;
        AliasNameType  _alias_name;
    };

    /**
     * @brief ストリーム出力演算
     *
     * @param[in] out    出力ストリーム
     * @param[in] column カラム指定オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, Column const column) -> std::ostream &;
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/specification/naming-rule.class.h++>

namespace sqlxx::specification
{
    Column::Column() : _column_name(), _alias_name()
    {}

    Column::Column(ColumnNameType column_name, AliasNameType alias_name)
        : _column_name(column_name), _alias_name(alias_name)
    {}

    auto Column::column_name(ColumnNameType column_name) -> Column &
    {
        this->_column_name = column_name;
        return *this;
    }

    auto Column::alias_name(AliasNameType alias_name) -> Column &
    {
        this->_alias_name = alias_name;
        return *this;
    }

    auto Column::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_column_name)) {
            return "";
        }

        std::string text = this->_column_name;
        if (NamingRule::is_legal(this->_alias_name, ".")) {
            text += " AS " + this->_alias_name;
        }
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, Column const column) -> std::ostream &
    {
        out << column.to_string();
        return out;
    }
}

#endif // SQLXX__SPECIFICATION__COLUMN_CLASS_HXX
