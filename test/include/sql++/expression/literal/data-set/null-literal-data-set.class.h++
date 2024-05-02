/*!
 * @file null-literal-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_HXX

#include <vector>

#include <sql++/expression/literal/null-literal.class.h++>

#include "./null-literal-data-set-element.class.h++"

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
     * @brief ≪NULLリテラル式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::NullLiteral              テスト対象クラス
     * @see sqlxx::test::expression::NullLiteralDataSet データセット要素
     */
    class NullLiteralDataSet
    {
    public:
        /*! @brief ≪NULLリテラル式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<NullLiteralDataSetElement>;

    private:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<NullLiteralDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * --------------------
     * |    | NullLiteral |
     * |    |-------------|
     * |    | inner_value |
     * |====|=============|
     * | _0 | -           |
     * |----|-------------|
     * | _1 | o           |
     * --------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - ... 未指定
     * @li o ... 指定
     *
     * [ 構成 ] @n
     * @li _0 ~ _1 : @link pattern_by_construction() @endlink
     *
     * @return ≪NULLリテラル式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::NullLiteral::inner_value() テスト対象メンバ関数
     * @see sqlxx::expression::NullLiteral::to_string()   テスト対象メンバ関数
     */
    auto NullLiteralDataSet::for_some_test_case()
        -> std::vector<NullLiteralDataSetElement>
    {
        return NullLiteralDataSet::pattern_by_construction();
    }

    /*!
     * [ データパターン ] @n
     * @c NullLiteral : 任意の引数により構築したオブジェクト
     *
     * @return ≪NULLリテラル式≫のテストケースで使用するデータセット
     */
    auto NullLiteralDataSet::pattern_by_construction()
        -> std::vector<NullLiteralDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + NullLiteral : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                NullLiteral {},

                // 期待結果 - inner_value メンバ関数
                nullptr,

                // 期待結果 - to_string メンバ関数
                "NULL",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + NullLiteral
            //     + inner_value : null-pointer
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                NullLiteral { nullptr },

                // 期待結果 - inner_value メンバ関数
                nullptr,

                // 期待結果 - to_string メンバ関数
                "NULL",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__NULL_LITERAL_DATA_SET_HXX */
