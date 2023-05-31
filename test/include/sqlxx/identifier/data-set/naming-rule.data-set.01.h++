/*!
 * @file naming-rule.data-set.01.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_01_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_01_HXX

#include <vector>

#include "./naming-rule-data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__NamingRule)

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li アルファベット大文字
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01A()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            "A", true
        }, {
            "B", true
        }, {
            "C", true
        }, {
            "D", true
        }, {
            "E", true
        }, {
            "F", true
        }, {
            "G", true
        }, {
            "H", true
        }, {
            "I", true
        }, {
            "J", true
        }, {
            "K", true
        }, {
            "L", true
        }, {
            "M", true
        }, {
            "N", true
        }, {
            "O", true
        }, {
            "P", true
        }, {
            "Q", true
        }, {
            "R", true
        }, {
            "S", true
        }, {
            "T", true
        }, {
            "U", true
        }, {
            "V", true
        }, {
            "W", true
        }, {
            "X", true
        }, {
            "Y", true
        }, {
            "Z", true
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li アルファベット小文字
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01a()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            "a", true
        }, {
            "b", true
        }, {
            "c", true
        }, {
            "d", true
        }, {
            "e", true
        }, {
            "f", true
        }, {
            "g", true
        }, {
            "h", true
        }, {
            "i", true
        }, {
            "j", true
        }, {
            "k", true
        }, {
            "l", true
        }, {
            "m", true
        }, {
            "n", true
        }, {
            "o", true
        }, {
            "p", true
        }, {
            "q", true
        }, {
            "r", true
        }, {
            "s", true
        }, {
            "t", true
        }, {
            "u", true
        }, {
            "v", true
        }, {
            "w", true
        }, {
            "x", true
        }, {
            "y", true
        }, {
            "z", true
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li 数字
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01d()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            "0", false
        }, {
            "1", false
        }, {
            "2", false
        }, {
            "3", false
        }, {
            "4", false
        }, {
            "5", false
        }, {
            "6", false
        }, {
            "7", false
        }, {
            "8", false
        }, {
            "9", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li 記号
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01s()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 適格
        ////////////////////////////////////////////////////////////////////////

        {
            "_", true
        },

        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////
        // NOTE : ASCII コード順

        {
            "!", false
        }, {
            "\"", false
        }, {
            "#", false
        }, {
            "$", false
        }, {
            "%", false
        }, {
            "&", false
        }, {
            "'", false
        }, {
            "(", false
        }, {
            ")", false
        }, {
            "*", false
        }, {
            "+", false
        }, {
            ",", false
        }, {
            "-", false
        }, {
            ".", false
        }, {
            "/", false
        }, {
            ":", false
        }, {
            ";", false
        }, {
            "<", false
        }, {
            "=", false
        }, {
            ">", false
        }, {
            "?", false
        }, {
            "@", false
        }, {
            "[", false
        }, {
            "\\", false
        }, {
            "]", false
        }, {
            "^", false
        }, {
            "`", false
        }, {
            "{", false
        }, {
            "|", false
        }, {
            "}", false
        }, {
            "~", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li 制御文字(空白文字を含む)
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01x()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            // NUL (空文字)
            "\0", false
        }, {
            // BEL (警報音)
            "\a", false
        }, {
            // BS (バックスペース)
            "\b", false
        }, {
            // HT (水平タブ)
            "\t", false
        }, {
            // LF / NL (改行)
            "\n", false
        }, {
            // VT (垂直タブ)
            "\v", false
        }, {
            // FF / NP (改ページ)
            "\f", false
        }, {
            // CR (行頭復帰)
            "\r", false
        }, {
            // SPC (空白文字)
            " ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 1
 * @li 全角文字
 *
 * @return データセット
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 */
auto NamingRuleDataSet::for_is_legal_01z()
    -> std::vector<NamingRuleDataSetElement>
{
    // clang-format off
    return {
        {
            // 全角アルファベット小文字
            "ａ", false
        }, {
            // 全角アルファベット大文字
            "Ａ", false
        }, {
            // 全角アンダースコア
            "＿", false
        }, {
            // 全角数字
            "０", false
        }, {
            // 全角アンダースコア以外の全角記号(全角ドルマーク)
            "＄", false
        }, {
            // 全角スペース
            "　", false
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__NamingRule */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_01_HXX */
