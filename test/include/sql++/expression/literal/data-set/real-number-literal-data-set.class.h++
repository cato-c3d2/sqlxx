/*!
 * @file real-number-literal-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__REAL_NUMBER_LITERAL_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__REAL_NUMBER_LITERAL_DATA_SET_HXX

#include <limits>
#include <vector>

#include <sql++/expression/literal/real-number-literal.class.h++>

#include "./real-number-literal-data-set-element.class.h++"

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
     * @brief ≪実数リテラル式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::RealNumberLiteral              テスト対象クラス
     * @see sqlxx::test::expression::RealNumberLiteralDataSet データセット要素
     */
    class RealNumberLiteralDataSet
    {
    public:
        /*! @brief ≪実数リテラル式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<RealNumberLiteralDataSetElement>;

    private:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<RealNumberLiteralDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * --------------------------
     * |    | RealNumberLiteral |
     * |    |-------------------|
     * |    | inner_value       |
     * |====|===================|
     * | _0 | -                 |
     * |----|-------------------|
     * | _1 | o (MIN - 0.1E+38) |
     * |----|-------------------|
     * | _2 | o (MIN)           |
     * |----|-------------------|
     * | _3 | o (-0.1)          |
     * |----|-------------------|
     * | _4 | o (0.0)           |
     * |----|-------------------|
     * | _5 | o (+0.1)          |
     * |----|-------------------|
     * | _6 | o (MAX)           |
     * |----|-------------------|
     * | _7 | o (MAX + 0.1E+38) |
     * --------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -   ... 未指定
     * @li o   ... 指定
     * @li MIN ... @c float の最小値（ @c -3.402823466E+38 ）
     * @li MAX ... @c float の最大値（ @c +3.402823466E+38 ）
     *
     * [ 構成 ] @n
     * @li _0 ~ _7 : @link pattern_by_construction() @endlink
     *
     * @return ≪実数リテラル式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::RealNumberLiteral::inner_value() テスト対象メンバ関数
     * @see sqlxx::expression::RealNumberLiteral::to_string()   テスト対象メンバ関数
     */
    auto RealNumberLiteralDataSet::for_some_test_case()
        -> std::vector<RealNumberLiteralDataSetElement>
    {
        return RealNumberLiteralDataSet::pattern_by_construction();
    }

    /*!
     * [ データパターン ] @n
     * @c RealNumberLiteral : 任意の引数により構築したオブジェクト
     *
     * @return ≪実数リテラル式≫のテストケースで使用するデータセット
     */
    auto RealNumberLiteralDataSet::pattern_by_construction()
        -> std::vector<RealNumberLiteralDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral {},

                // 期待結果 - inner_value メンバ関数
                0.0f,

                // 期待結果 - to_string メンバ関数
                "0.000000",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : -3.402823466E+38 - 0.1E+38 （ float 型の最小値 - 0.1E+38 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral {
                    // NOTE std::numeric_limits<float>::min() は非ゼロの正の値の最小値を返すため、
                    //      代わりに lowest() を使用する。
                    std::numeric_limits<float>::lowest() - 0.1e38f,
                },

                // 期待結果 - inner_value メンバ関数
                // NOTE 浮動小数点数のオーバーフローが発生し、値は負の無限大になる。
                std::numeric_limits<float>::infinity() * -1.0f,

                // 期待結果 - to_string メンバ関数
                "-inf",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : -3.402823466E+38 （ float 型の最小値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral {
                    // NOTE std::numeric_limits<float>::min() は非ゼロの正の値の最小値を返すため、
                    //      代わりに lowest() を使用する。
                    std::numeric_limits<float>::lowest(),
                },

                // 期待結果 - inner_value メンバ関数
                -340282346638528859811704183484516925440.0f,

                // 期待結果 - to_string メンバ関数
                "-340282346638528859811704183484516925440.000000",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : -0.1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral { -0.1f },

                // 期待結果 - inner_value メンバ関数
                -0.1f,

                // 期待結果 - to_string メンバ関数
                "-0.100000",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : 0.0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral { 0.0f },

                // 期待結果 - inner_value メンバ関数
                0.0f,

                // 期待結果 - to_string メンバ関数
                "0.000000",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : +0.1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral { 0.1f },

                // 期待結果 - inner_value メンバ関数
                0.1f,

                // 期待結果 - to_string メンバ関数
                "0.100000",
            },

            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : +3.402823466E+38 （ float 型の最大値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral {
                    std::numeric_limits<float>::max(),
                },

                // 期待結果 - inner_value メンバ関数
                340282346638528859811704183484516925440.0f,

                // 期待結果 - to_string メンバ関数
                "340282346638528859811704183484516925440.000000",
            },

            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + RealNumberLiteral
            //     + inner_value : +3.402823466E+38 + 0.1E+38 （ float 型の最大値 + 0.1E+38 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                RealNumberLiteral {
                    std::numeric_limits<float>::max() + 0.1e38f,
                },

                // 期待結果 - inner_value メンバ関数
                // NOTE 浮動小数点数のオーバーフローが発生し、値は正の無限大になる。
                std::numeric_limits<float>::infinity(),

                // 期待結果 - to_string メンバ関数
                "inf",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__REAL_NUMBER_LITERAL_DATA_SET_HXX */
