/*!
 * @file table-identifier.class.h++
 */

#ifndef SQLXX__IDENTIFIER__TABLE_IDENTIFIER_CLASS_HXX
#define SQLXX__IDENTIFIER__TABLE_IDENTIFIER_CLASS_HXX

#include <sql++/closure/as-closure.class.h++>
#include <sql++/identifier/naming-rule.class.h++>

#include <string>

namespace sqlxx
{
inline namespace identifier
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief テーブル指定の文法クラス
     */
    class TableIdentifier
    {
    public:
        /*!
         * @brief テーブル名の型
         */
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
        TableIdentifier();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       テーブル名
         * @param[in] as_closure "AS 句" の文法オブジェクト
         */
        TableIdentifier(NameType name, closure::AsClosure as_closure = {});

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       テーブル名
         * @param[in] alias_name エイリアス名
         *
         * @deprecated @link
         *             TableIdentifier::TableIdentifier(NameType name, closure::AsClosure as_closure = {})
         *             @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'TableIdentifier::TableIdentifier(NameType, AsClosure)'")]]
        // clang-format on
        TableIdentifier(NameType name, AliasNameType alias_name);

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] name テーブル名
         *
         * @return このオブジェクトの参照
         */
        auto name(NameType name) -> TableIdentifier &;

        /*!
         * @brief テーブル名を設定する
         *
         * @param[in] name テーブル名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link TableIdentifier::name(NameType table_name) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'TableIdentifier::name(NameType)'")]]
        // clang-format on
        auto
        table_name(NameType name) -> TableIdentifier &;

        /*!
         * @brief "AS 句" を設定する
         *
         * @param[in] as_closure "AS 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto as(closure::AsClosure as_closure) -> TableIdentifier &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link TableIdentifier::as(closure::AsClosure as_closure) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'TableIdentifier::as(closure::AsClosure)'")]]
        // clang-format on
        auto
        alias_name(AliasNameType alias_name) -> TableIdentifier &;

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
         * @brief テーブル名
         */
        NameType _name;

        /*!
         * @brief "AS 句"
         */
        closure::AsClosure _as_closure;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] table_identifier テーブル指定の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, TableIdentifier const table_identifier)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    TableIdentifier::TableIdentifier() : _name(), _as_closure()
    {}

    TableIdentifier::TableIdentifier(
        NameType name, closure::AsClosure as_closure)
        : _name(name), _as_closure(as_closure)
    {}

    TableIdentifier::TableIdentifier(NameType name, AliasNameType alias_name)
        : _name(name), _as_closure(closure::AsClosure { alias_name })
    {}

    auto TableIdentifier::name(NameType name) -> TableIdentifier &
    {
        this->_name = name;
        return *this;
    }

    auto TableIdentifier::table_name(NameType name) -> TableIdentifier &
    {
        this->_name = name;
        return *this;
    }

    auto TableIdentifier::as(closure::AsClosure as_closure) -> TableIdentifier &
    {
        this->_as_closure = as_closure;
        return *this;
    }

    auto TableIdentifier::alias_name(AliasNameType alias_name)
        -> TableIdentifier &
    {
        this->_as_closure.alias_name(alias_name);
        return *this;
    }

    auto TableIdentifier::empty() const -> bool
    {
        return ! NamingRule::is_legal(this->_name);
    }

    auto TableIdentifier::to_string() const -> std::string
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
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, TableIdentifier const table_identifier)
        -> std::ostream &
    {
        out << table_identifier.to_string();
        return out;
    }
} // namespace identifier
} // namespace sqlxx

#endif // SQLXX__IDENTIFIER__TABLE_IDENTIFIER_CLASS_HXX
