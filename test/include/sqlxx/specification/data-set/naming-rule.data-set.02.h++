/*!
 * @file naming-rule.data-set.02.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_02_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_02_HXX

#include <vector>

#include "./naming-rule.data-set-element.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__NamingRule)

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li アルファベット大文字 + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02A() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "AZ", true
        }, {
            // アルファベット小文字
            "Az", true
        }, {
            // アンダースコア
            "A_", true
        }, {
            // 数字
            "A9", true
        },

        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アンダースコア以外の記号(ドルマーク)
            "A$", false
        }, {
            // 空白文字
            "A ", false
        }, {
            // 制御文字(改行)
            "A\n", false
        }, {
            // 全角文字
            "Aあ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li アルファベット小文字 + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02a() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "aZ", true
        }, {
            // アルファベット小文字
            "az", true
        }, {
            // アンダースコア
            "a_", true
        }, {
            // 数字
            "a9", true
        },

        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アンダースコア以外の記号(ドルマーク)
            "a$", false
        }, {
            // 空白文字
            "a ", false
        }, {
            // 制御文字(改行)
            "a\n", false
        }, {
            // 全角文字
            "aあ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li アンダースコア + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02c() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "_Z", true
        }, {
            // アルファベット小文字
            "_z", true
        }, {
            // アンダースコア
            "__", true
        }, {
            // 数字
            "_9", true
        },

        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アンダースコア以外の記号(ドルマーク)
            "_$", false
        }, {
            // 空白文字
            "_ ", false
        }, {
            // 制御文字(改行)
            "_\n", false
        }, {
            // 全角文字
            "_あ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li 数字 + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02d() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "0Z", false
        }, {
            // アルファベット小文字
            "0z", false
        }, {
            // アンダースコア
            "0_", false
        }, {
            // 数字
            "09", false
        }, {
            // アンダースコア以外の記号(ドルマーク)
            "0$", false
        }, {
            // 空白文字
            "0 ", false
        }, {
            // 制御文字(改行)
            "0\n", false
        }, {
            // 全角文字
            "0あ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li アンダースコア以外の記号(ドルマーク) + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02e() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "$Z", false
        }, {
            // アルファベット小文字
            "$z", false
        }, {
            // アンダースコア
            "$_", false
        }, {
            // 数字
            "$9", false
        }, {
            // アンダースコア以外の記号(ドルマーク)
            "$$", false
        }, {
            // 空白文字
            "$0 ", false
        }, {
            // 制御文字(改行)
            "$\n", false
        }, {
            // 全角文字
            "$あ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li 空白文字 + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02f() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            " Z", false
        }, {
            // アルファベット小文字
            " z", false
        }, {
            // アンダースコア
            " _", false
        }, {
            // 数字
            " 9", false
        }, {
            // アンダースコア以外の記号(ドルマーク)
            " $", false
        }, {
            // 空白文字
            "  ", false
        }, {
            // 制御文字(改行)
            " \n", false
        }, {
            // 全角文字
            " あ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li 制御文字(改行) + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02g() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "\nZ", false
        }, {
            // アルファベット小文字
            "\nz", false
        }, {
            // アンダースコア
            "\n_", false
        }, {
            // 数字
            "\n9", false
        }, {
            // アンダースコア以外の記号(ドルマーク)
            "\n$", false
        }, {
            // 空白文字
            "\n ", false
        }, {
            // 制御文字(改行)
            "\n\n", false
        }, {
            // 全角文字
            "\nあ", false
        }
    };
    // clang-format on
}

/*!
 * @brief データセットを返却する
 *
 * データパターン : @n
 * @li 文字数 : @c 2
 * @li 全角文字 + 任意の文字
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal_02h() -> std::vector<DataSetElement>
{
    // clang-format off
    return {
        ////////////////////////////////////////////////////////////////////////
        // 不適格
        ////////////////////////////////////////////////////////////////////////

        {
            // アルファベット大文字
            "あZ", false
        }, {
            // アルファベット小文字
            "あz", false
        }, {
            // アンダースコア
            "あ_", false
        }, {
            // 数字
            "あ9", false
        }, {
            // アンダースコア以外の記号(ドルマーク)
            "あ$", false
        }, {
            // 空白文字
            "あ ", false
        }, {
            // 制御文字(改行)
            "あ\n", false
        }, {
            // 全角文字
            "ああ", false
        }
    };
    // clang-format on
}

BOOST_AUTO_TEST_SUITE_END(/* class__NamingRule */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_02_HXX */
