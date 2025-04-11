/*!
 * @file integer-literal-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_HXX

#include <limits>
#include <vector>

#include <sql++/expression/literal/integer-literal.class.h++>

#include "./integer-literal-data-set-element.class.h++"

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
     * @brief ≪整数リテラル式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::IntegerLiteral              テスト対象クラス
     * @see sqlxx::test::expression::IntegerLiteralDataSet データセット要素
     */
    class IntegerLiteralDataSet
    {
    public:
        /*! @brief ≪整数リテラル式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<IntegerLiteralDataSetElement>;

    private:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<IntegerLiteralDataSetElement>;
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
     * |    | IntegerLiteral |
     * |    |----------------|
     * |    | inner_value    |
     * |====|================|
     * | _0 | -              |
     * |----|----------------|
     * | _1 | o (MIN - 1)    |
     * |----|----------------|
     * | _2 | o (MIN)        |
     * |----|----------------|
     * | _3 | o (-1)         |
     * |----|----------------|
     * | _4 | o (0)          |
     * |----|----------------|
     * | _5 | o (+1)         |
     * |----|----------------|
     * | _6 | o (MAX)        |
     * |----|----------------|
     * | _7 | o (MAX + 1)    |
     * -----------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -   ... 未指定
     * @li o   ... 指定
     * @li MIN ... @c int の最小値（ @c -2,147,483,648 ）
     * @li MAX ... @c int の最大値（ @c +2,147,483,647 ）
     *
     * [ 構成 ] @n
     * @li _0 ~ _7 : @link pattern_by_construction() @endlink
     *
     * @return ≪整数リテラル式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::IntegerLiteral::inner_value() テスト対象メンバ関数
     * @see sqlxx::expression::IntegerLiteral::to_string()   テスト対象メンバ関数
     */
    auto IntegerLiteralDataSet::for_some_test_case()
        -> std::vector<IntegerLiteralDataSetElement>
    {
        return IntegerLiteralDataSet::pattern_by_construction();
    }

    /*!
     * [ データパターン ] @n
     * @c IntegerLiteral : 任意の引数により構築したオブジェクト
     *
     * @return ≪整数リテラル式≫のテストケースで使用するデータセット
     */
    auto IntegerLiteralDataSet::pattern_by_construction()
        -> std::vector<IntegerLiteralDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral {},

                // 期待結果 - inner_value メンバ関数
                0,

                // 期待結果 - to_string メンバ関数
                "0",
            },

            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : -2,147,483,649 （ int 型の最小値 - 1 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { std::numeric_limits<int>::min() - 1 },

                // 期待結果 - inner_value メンバ関数
                // NOTE アンダーフローすること
                2'147'483'647,

                // 期待結果 - to_string メンバ関数
                "2147483647",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : -2,147,483,648 （ int 型の最小値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { std::numeric_limits<int>::min() },

                // 期待結果 - inner_value メンバ関数
                -2'147'483'648,

                // 期待結果 - to_string メンバ関数
                "-2147483648",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : -1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { -1 },

                // 期待結果 - inner_value メンバ関数
                -1,

                // 期待結果 - to_string メンバ関数
                "-1",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : 0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { 0 },

                // 期待結果 - inner_value メンバ関数
                0,

                // 期待結果 - to_string メンバ関数
                "0",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : +1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { 1 },

                // 期待結果 - inner_value メンバ関数
                1,

                // 期待結果 - to_string メンバ関数
                "1",
            },

            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : +2,147,483,647 （ int 型の最大値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { std::numeric_limits<int>::max() },

                // 期待結果 - inner_value メンバ関数
                2'147'483'647,

                // 期待結果 - to_string メンバ関数
                "2147483647",
            },

            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + IntegerLiteral
            //     + inner_value : +2,147,483,648 （ int 型の最大値 + 1 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                IntegerLiteral { std::numeric_limits<int>::max() + 1 },

                // 期待結果 - inner_value メンバ関数
                // NOTE オーバーフローすること
                -2'147'483'648,

                // 期待結果 - to_string メンバ関数
                "-2147483648",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__INTEGER_LITERAL_DATA_SET_HXX */
