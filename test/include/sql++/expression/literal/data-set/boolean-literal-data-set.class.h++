/*!
 * @file boolean-literal-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BOOLEAN_LITERAL_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BOOLEAN_LITERAL_DATA_SET_HXX

#include <vector>

#include <sql++/expression/literal/boolean-literal.class.h++>

#include "./boolean-literal-data-set-element.class.h++"

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
     * @brief ≪論理値リテラル式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::BooleanLiteral              テスト対象クラス
     * @see sqlxx::test::expression::BooleanLiteralDataSet データセット要素
     */
    class BooleanLiteralDataSet
    {
    public:
        /*! @brief ≪論理値リテラル式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<BooleanLiteralDataSetElement>;

    private:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<BooleanLiteralDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -----------------------
     * |    | BooleanLiteral |
     * |    |----------------|
     * |    | inner_value    |
     * |====|================|
     * | _0 | -              |
     * |----|----------------|
     * | _1 | o (false)      |
     * |----|----------------|
     * | _2 | o (true)       |
     * -----------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - ... 未指定
     * @li o ... 指定
     *
     * [ 構成 ] @n
     * @li _0 ~ _2 : @link pattern_by_construction() @endlink
     *
     * @return ≪論理値リテラル式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::BooleanLiteral::inner_value() テスト対象メンバ関数
     * @see sqlxx::expression::BooleanLiteral::to_string()   テスト対象メンバ関数
     */
    auto BooleanLiteralDataSet::for_some_test_case()
        -> std::vector<BooleanLiteralDataSetElement>
    {
        return BooleanLiteralDataSet::pattern_by_construction();
    }

    /*!
     * [ データパターン ] @n
     * @c BooleanLiteral : 任意の引数により構築したオブジェクト
     *
     * @return ≪論理値リテラル式≫のテストケースで使用するデータセット
     */
    auto BooleanLiteralDataSet::pattern_by_construction()
        -> std::vector<BooleanLiteralDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BooleanLiteral : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BooleanLiteral {},

                // 期待結果 - inner_value メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                // FIXME [要不具合修正] 実行結果と期待結果が一致しない。
                // "FALSE",
                "false",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BooleanLiteral
            //     + inner_value : 偽
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BooleanLiteral { false },

                // 期待結果 - inner_value メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                // FIXME [要不具合修正] 実行結果と期待結果が一致しない。
                // "FALSE",
                "false",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BooleanLiteral
            //     + inner_value : 真
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                BooleanLiteral { true },

                // 期待結果 - inner_value メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                // FIXME [要不具合修正] 実行結果と期待結果が一致しない。
                // "TRUE",
                "true",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__BOOLEAN_LITERAL_DATA_SET_HXX */
