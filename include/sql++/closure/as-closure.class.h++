/*!
 * @file as-closure.class.h++
 */

#ifndef SQLXX__CLOSURE__AS_CLOSURE_CLASS_HXX
#define SQLXX__CLOSURE__AS_CLOSURE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

namespace sqlxx
{
inline namespace closure
{
    /*!
     * @brief "AS 句" の文法クラス
     */
    class AsClosure
    {
    public:
        /*!
         * @brief エイリアス名の型
         */
        using AliasNameType = std::string;

        /*!
         * @brief デフォルトコンストラクタ
         */
        AsClosure();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] alias_name  エイリアス名
         */
        AsClosure(AliasNameType alias_name);

        /*!
         * @brief エイリアス名を設定する
         *
         * @param[in] alias_name エイリアス名
         *
         * @return このオブジェクトの参照
         */
        auto alias_name(AliasNameType alias_name) -> AsClosure &;

        /*!
         * @brief エイリアス名を取得する
         *
         * @return エイリアス名
         */
        auto alias_name() const -> AliasNameType;

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
         * @brief "AS 句"
         */
        AliasNameType _alias_name;
    };

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out        出力ストリーム
     * @param[in] as_closure "AS 句" の文法オブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(std::ostream & out, AsClosure const as_closure)
        -> std::ostream &;
} // namespace closure
} // namespace sqlxx

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx
{
inline namespace closure
{
    AsClosure::AsClosure() : _alias_name()
    {}

    AsClosure::AsClosure(AliasNameType alias_name) : _alias_name(alias_name)
    {}

    auto AsClosure::alias_name() const -> AliasNameType
    {
        return this->_alias_name;
    }

    auto AsClosure::alias_name(AliasNameType alias_name) -> AsClosure &
    {
        this->_alias_name = alias_name;
        return *this;
    }

    auto AsClosure::empty() const -> bool
    {
        bool is_legal;
        if (this->_alias_name.find(".") == std::string::npos) {
            is_legal = identifier::NamingRule::is_legal(this->_alias_name);
        } else {
            is_legal = identifier::NamingRule::is_legal(this->_alias_name, ".");
        }
        return ! is_legal;
    }

    auto AsClosure::to_string() const -> std::string
    {
        if (this->empty()) {
            return "";
        }
        return "AS " + this->_alias_name;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Function definition
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(std::ostream & out, AsClosure const as_closure)
        -> std::ostream &
    {
        out << as_closure.to_string();
        return out;
    }
} // namespace closure
} // namespace sqlxx

#endif // SQLXX__CLOSURE__AS_CLOSURE_CLASS_HXX
