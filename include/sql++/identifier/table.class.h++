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

namespace sqlxx
{
inline namespace identifier
{
    /*!
     * @brief テーブル指定の文法クラス
     */
    class Table
    {
    public:
        /*! @brief テーブル名の型 */
        using NameType = std::string;

        /*!
         * @brief エイリアス名の型
         *
         * @deprecated
         */
        using AliasNameType [[deprecated]] = closure::AsClosure::AliasNameType;

        /*!
         * @brief デフォルトコンストラクタ
         */
        Table();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       テーブル名
         * @param[in] as_closure "AS 句" の文法オブジェクト
         */
        Table(NameType name, closure::AsClosure as_closure = {});

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       テーブル名
         * @param[in] alias_name エイリアス名
         *
         * @deprecated @link
         *             Table::Table(NameType name, closure::AsClosure as_closure = {})
         *             @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'Table::Table(NameType, AsClosure)'")]]
        // clang-format on
        Table(NameType name, AliasNameType alias_name);

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] name テーブル名
         *
         * @return このオブジェクトの参照
         */
        auto name(NameType name) -> Table &;

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] name テーブル名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link Table::name(NameType table_name) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'Table::name(NameType)'")]]
        // clang-format on
        auto
        table_name(NameType name) -> Table &;

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
         *
         * @deprecated @link Table::as(closure::AsClosure as_closure) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'Table::as(closure::AsClosure)'")]]
        // clang-format on
        auto
        alias_name(AliasNameType alias_name) -> Table &;

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
        NameType           _name;
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
} // namespace identifier
} // namespace sqlxx

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx
{
inline namespace identifier
{
    Table::Table() : _name(), _as_closure()
    {}

    Table::Table(NameType name, closure::AsClosure as_closure)
        : _name(name), _as_closure(as_closure)
    {}

    Table::Table(NameType name, AliasNameType alias_name)
        : _name(name), _as_closure(closure::AsClosure { alias_name })
    {}

    auto Table::name(NameType name) -> Table &
    {
        this->_name = name;
        return *this;
    }

    auto Table::table_name(NameType name) -> Table &
    {
        this->_name = name;
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
        return ! NamingRule::is_legal(this->_name);
    }

    auto Table::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_name)) {
            return "";
        }
        std::string text = this->_name;
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
} // namespace identifier
} // namespace sqlxx

#endif // SQLXX__IDENTIFIER__TABLE_CLASS_HXX
