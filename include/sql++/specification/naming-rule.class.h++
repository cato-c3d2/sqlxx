/*!
 * @file naming-rule.class.h++
 */

#ifndef SQLXX__SPECIFICATION__NAMING_RULE_CLASS_HXX
#define SQLXX__SPECIFICATION__NAMING_RULE_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition / Class member declaration / Function declaration
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

namespace sqlxx::specification
{
    /*!
     * @brief 識別子の命名規則に関するクラス
     */
    class NamingRule
    {
    public:
        /*!
         * @brief 識別子が命名規則に則っているか判定する
         *
         * @param[in] identifier 識別子
         *
         * @return 識別子が命名規則に則っている場合は @c true を,
         *         そうではない場合は @c false を返却する
         *
         * @see NamingRule::pattern() 識別子の命名規則の正規表現パターン
         */
        static auto is_legal(std::string identifier) -> bool;

        /*!
         * @brief 識別子が命名規則に則っているか判定する
         *
         * 識別子が区切り文字で分割されているケースについて,
         * 区切り文字とその前後の識別子が命名規則に則っているか判定する.
         *
         * 例えば, @c "table_alias_name.column_name" 等である. @n
         * この場合, 区切り文字( @c delimiter ) は @c "." である. @n
         *
         * @param[in] identifier 識別子
         * @param[in] delimiter  区切り文字
         *
         * @return 識別子が命名規則に則っている場合は @c true を,
         *         そうではない場合は @c false を返却する
         *
         * @see NamingRule::pattern() 識別子の命名規則の正規表現パターン
         */
        static auto is_legal(std::string identifier, std::string delimiter)
            -> bool;

        /*!
         * @brief 識別子の命名規則の正規表現パターンを返却する
         *
         * 識別子の命名規則について : @n
         * 先頭の文字として, アルファベットまたはアンダースコアが使用できる. @n
         * 以降の文字として, アルファベット, アンダースコアまたは数字が使用できる. @n
         *
         * @return 識別子の命名規則の正規表現パターン
         */
        static auto pattern() -> std::string;
    };
}

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition / Function definition
//
////////////////////////////////////////////////////////////////////////////////

#include <regex>

namespace sqlxx::specification
{
    auto NamingRule::is_legal(std::string identifier) -> bool
    {
        return std::regex_search(
            identifier, std::regex { "^" + NamingRule::pattern() + "$" });
    }

    auto NamingRule::is_legal(std::string identifier, std::string delimiter)
        -> bool
    {
        // clang-format off
        return std::regex_search(
            identifier,
            std::regex {
                "^" + NamingRule::pattern()
                    + delimiter
                    + NamingRule::pattern() + "$" });
        // clang-format on
    }

    auto NamingRule::pattern() -> std::string
    {
        static auto const value = R"([a-zA-Z_]\w*)";
        return value;
    }
}

#endif // SQLXX__SPECIFICATION__NAMING_RULE_CLASS_HXX
