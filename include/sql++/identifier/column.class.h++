/*!
 * @file column.class.h++
 */

#ifndef SQLXX__IDENTIFIER__COLUMN_CLASS_HXX
#define SQLXX__IDENTIFIER__COLUMN_CLASS_HXX

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
     * @brief カラム指定の文法クラス
     */
    class Column
    {
    public:
        /*! @brief カラム名の型 */
        using ColumnNameType = std::string;

        /*! @brief エイリアス名の型 */
        using AliasNameType = closure::AsClosure::AliasNameType;

        /*!
         * @brief デフォルトコンストラクタ
         */
        Column();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] column_name カラム名
         * @param[in] as_closure  "AS 句" の文法オブジェクト
         */
        Column(ColumnNameType column_name, closure::AsClosure as_closure = {});

        /*!
         * @brief コンストラクタ
         *
         * @param[in] column_name カラム名
         * @param[in] alias_name  エイリアス名
         */
        Column(ColumnNameType column_name, AliasNameType alias_name);

        /*!
         * @brief カラム名を設定する
         *
         * @param[in] column_name カラム名
         *
         * @return このオブジェクトの参照
         */
        auto column_name(ColumnNameType column_name) -> Column &;

        /*!
         * @brief "AS 句" を設定する
         *
         * @param[in] as_closure "AS 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto as(closure::AsClosure as_closure) -> Column &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link Column::as(closure::AsClosure as_closure) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'Column::as(closure::AsClosure)'")]]
        // clang-format on
        auto
        alias_name(AliasNameType alias_name) -> Column &;

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
        ColumnNameType     _column_name;
        closure::AsClosure _as_closure;
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

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx::identifier
{
    Column::Column() : _column_name(), _as_closure()
    {}

    Column::Column(ColumnNameType column_name, closure::AsClosure as_closure)
        : _column_name(column_name), _as_closure(as_closure)
    {}

    Column::Column(ColumnNameType column_name, AliasNameType alias_name)
        : _column_name(column_name)
        , _as_closure(closure::AsClosure { alias_name })
    {}

    auto Column::column_name(ColumnNameType column_name) -> Column &
    {
        this->_column_name = column_name;
        return *this;
    }

    auto Column::as(closure::AsClosure as_closure) -> Column &
    {
        this->_as_closure = as_closure;
        return *this;
    }

    auto Column::alias_name(AliasNameType alias_name) -> Column &
    {
        this->_as_closure.alias_name(alias_name);
        return *this;
    }

    auto Column::empty() const -> bool
    {
        return ! NamingRule::is_legal(this->_column_name);
    }

    auto Column::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_column_name)) {
            return "";
        }

        std::string text = this->_column_name;
        if (NamingRule::is_legal(this->_as_closure.alias_name(), ".")) {
            text += " " + this->_as_closure.to_string();
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

#endif // SQLXX__IDENTIFIER__COLUMN_CLASS_HXX
