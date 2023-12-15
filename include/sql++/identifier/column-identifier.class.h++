/*!
 * @file column-identifier.class.h++
 */

#ifndef SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_HXX
#define SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_HXX

#include <string>

#include <sql++/closure/as-closure.class.h++>
#include <sql++/identifier/naming-rule.class.h++>

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
     * @brief カラム指定の文法クラス
     */
    class ColumnIdentifier
    {
    public:
        /*!
         * @brief カラム名の型
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
        ColumnIdentifier();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       カラム名
         * @param[in] as_closure "AS 句" の文法オブジェクト
         */
        ColumnIdentifier(NameType name, closure::AsClosure as_closure = {});

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name       カラム名
         * @param[in] alias_name エイリアス名
         *
         * @deprecated @link
         *             ColumnIdentifier::ColumnIdentifier(NameType name, closure::AsClosure as_closure = {})
         *             @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'ColumnIdentifier::ColumnIdentifier(NameType, AsClosure)'")]]
        // clang-format on
        ColumnIdentifier(NameType name, AliasNameType alias_name);

        /*!
         * @brief カラム名を設定する
         *
         * @param[in] name カラム名
         *
         * @return このオブジェクトの参照
         */
        auto name(NameType name) -> ColumnIdentifier &;

        /*!
         * @brief カラム名を設定する
         *
         * @param[in] name カラム名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link ColumnIdentifier::name(NameType column_name) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'ColumnIdentifier::name(NameType)'")]]
        // clang-format on
        auto
        column_name(NameType name) -> ColumnIdentifier &;

        /*!
         * @brief "AS 句" を設定する
         *
         * @param[in] as_closure "AS 句" の文法オブジェクト
         *
         * @return このオブジェクトの参照
         */
        auto as(closure::AsClosure as_closure) -> ColumnIdentifier &;

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         *
         * @deprecated @link ColumnIdentifier::as(closure::AsClosure as_closure) @endlink を使用してください
         */
        // clang-format off
        [[deprecated("please use 'ColumnIdentifier::as(closure::AsClosure)'")]]
        // clang-format on
        auto
        alias_name(AliasNameType alias_name) -> ColumnIdentifier &;

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
         * @brief カラム名
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
     * @param[in] out               出力ストリーム
     * @param[in] column_identifier カラム指定オブジェクト
     *
     * @return 出力ストリーム
     */
    auto
    operator<<(std::ostream & out, ColumnIdentifier const column_identifier)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    ColumnIdentifier::ColumnIdentifier() : _name(), _as_closure()
    {}

    ColumnIdentifier::ColumnIdentifier(
        NameType name, closure::AsClosure as_closure)
        : _name(name), _as_closure(as_closure)
    {}

    ColumnIdentifier::ColumnIdentifier(NameType name, AliasNameType alias_name)
        : _name(name), _as_closure(closure::AsClosure { alias_name })
    {}

    auto ColumnIdentifier::name(NameType name) -> ColumnIdentifier &
    {
        this->_name = name;
        return *this;
    }

    auto ColumnIdentifier::column_name(NameType name) -> ColumnIdentifier &
    {
        this->_name = name;
        return *this;
    }

    auto ColumnIdentifier::as(closure::AsClosure as_closure)
        -> ColumnIdentifier &
    {
        this->_as_closure = as_closure;
        return *this;
    }

    auto ColumnIdentifier::alias_name(AliasNameType alias_name)
        -> ColumnIdentifier &
    {
        this->_as_closure.alias_name(alias_name);
        return *this;
    }

    auto ColumnIdentifier::empty() const -> bool
    {
        return ! NamingRule::is_legal(this->_name);
    }

    auto ColumnIdentifier::to_string() const -> std::string
    {
        if (! NamingRule::is_legal(this->_name)) {
            return "";
        }

        std::string text = this->_name;
        if (NamingRule::is_legal(this->_as_closure.alias_name(), ".")) {
            text += " " + this->_as_closure.to_string();
        }
        return text;
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto
    operator<<(std::ostream & out, ColumnIdentifier const column_identifier)
        -> std::ostream &
    {
        out << column_identifier.to_string();
        return out;
    }
} // namespace identifier
} // namespace sqlxx

#endif // SQLXX__IDENTIFIER__COLUMN_IDENTIFIER_CLASS_HXX
