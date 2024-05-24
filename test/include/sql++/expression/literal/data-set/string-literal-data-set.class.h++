/*!
 * @file string-literal-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_HXX

#include <vector>

#include <sql++/expression/literal/string-literal.class.h++>

#include "./string-literal-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪文字列リテラル式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::StringLiteral              テスト対象クラス
     * @see sqlxx::test::expression::StringLiteralDataSet データセット要素
     */
    class StringLiteralDataSet
    {
    public:
        /*! @brief ≪文字列リテラル式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<StringLiteralDataSetElement>;

    private:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<StringLiteralDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -------------------------
     * |    | StringLiteral    |
     * |    |------------------|
     * |    | inner_value      |
     * |====|==================|
     * | _0 | -                |
     * |----|------------------|
     * | _1 | o (empty-string) |
     * |----|------------------|
     * | _2 | o (white-space)  |
     * |----|------------------|
     * | _3 | o (any-string)   |
     * -------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -            ... 未指定
     * @li o            ... 指定
     * @li empty-string ... 空文字列
     * @li white-space  ... 半角スペース
     * @li any-string   ... 任意の文字列
     *
     * [ 構成 ] @n
     * @li _0 ~ _3 : @link pattern_by_construction() @endlink
     *
     * @return ≪文字列リテラル式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::StringLiteral::inner_value() テスト対象メンバ関数
     * @see sqlxx::expression::StringLiteral::to_string()   テスト対象メンバ関数
     */
    auto StringLiteralDataSet::for_some_test_case()
        -> std::vector<StringLiteralDataSetElement>
    {
        return StringLiteralDataSet::pattern_by_construction();
    }

    /*!
     * [ データパターン ] @n
     * @c StringLiteral : 任意の引数により構築したオブジェクト
     *
     * @return ≪文字列リテラル式≫のテストケースで使用するデータセット
     */
    auto StringLiteralDataSet::pattern_by_construction()
        -> std::vector<StringLiteralDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + StringLiteral : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                StringLiteral {},

                // 期待結果 - inner_value メンバ関数
                "",

                // 期待結果 - to_string メンバ関数
                "''",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + StringLiteral
            //     + inner_value : 空文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                StringLiteral { "" },

                // 期待結果 - inner_value メンバ関数
                "",

                // 期待結果 - to_string メンバ関数
                "''",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + StringLiteral
            //     + inner_value : 半角スペース
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                StringLiteral { " " },

                // 期待結果 - inner_value メンバ関数
                " ",

                // 期待結果 - to_string メンバ関数
                "' '",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + StringLiteral
            //     + inner_value : 任意の文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                StringLiteral { "This is a test string." },

                // 期待結果 - inner_value メンバ関数
                "This is a test string.",

                // 期待結果 - to_string メンバ関数
                "'This is a test string.'",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__STRING_LITERAL_DATA_SET_HXX */
