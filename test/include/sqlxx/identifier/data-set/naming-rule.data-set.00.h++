/*!
 * @file naming-rule.data-set.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_00_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_00_HXX

#include <vector>

#include "./naming-rule-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__NamingRule)

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 任意の文字で始まり, 続く文字列に下記の文字を含む :
 *     + 全てのアルファベット小文字(a ~ z)
 *     + 全てのアルファベット大文字(A ~ Z)
 *     + 全ての数字(0 ~ 9)
 *     + アンダースコア
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_() -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            // 識別子 :
            // + アルファベット小文字で始まり, 続く文字列に下記の文字を含む :
            //   + 全てのアルファベット小文字(a ~ z)
            //   + 全てのアルファベット大文字(A ~ Z)
            //   + 全ての数字(0 ~ 9)
            //   + アンダースコア
            "aabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
            // 期待結果 : 適格
            true
        }, {
            // 識別子 :
            // + アルファベット大文字で始まり, 続く文字列に下記の文字を含む :
            //   + 全てのアルファベット小文字(a ~ z)
            //   + 全てのアルファベット大文字(A ~ Z)
            //   + 全ての数字(0 ~ 9)
            //   + アンダースコア
            "AabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
            // 期待結果 : 適格
            true
        }, {
            // 識別子 :
            // + アンダースコアで始まり, 続く文字列に下記の文字を含む :
            //   + 全てのアルファベット小文字(a ~ z)
            //   + 全てのアルファベット大文字(A ~ Z)
            //   + 全ての数字(0 ~ 9)
            //   + アンダースコア
            "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
            // 期待結果 : 適格
            true
        }, {
            // 識別子 :
            // + 数字で始まり, 続く文字列に下記の文字を含む :
            //   + 全てのアルファベット小文字(a ~ z)
            //   + 全てのアルファベット大文字(A ~ Z)
            //   + 全ての数字(0 ~ 9)
            //   + アンダースコア
            "0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_",
            // 期待結果 : 不適格
            false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 0
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_00() -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            // 空文字列
            "", false
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__NamingRule */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_00_HXX */