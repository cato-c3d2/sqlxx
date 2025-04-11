/*!
 * @file grouped-expression-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_HXX

#include <iterator>
#include <limits>
#include <vector>

#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/boolean-literal.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/literal/null-literal.class.h++>
#include <sql++/expression/literal/real-number-literal.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>

#include "./grouped-expression-data-set-element.class.h++"

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
     * @brief ≪グループ化された式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::GroupedExpression              テスト対象クラス
     * @see sqlxx::test::expression::GroupedExpressionDataSet データセット要素
     */
    class GroupedExpressionDataSet
    {
    public:
        /*! @brief ≪グループ化された式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<GroupedExpressionDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<GroupedExpressionDataSetElement>;

        /*! @brief データパターン : ≪識別子式≫を指定する */
        static auto pattern_by_identifier_expression()
            -> std::vector<GroupedExpressionDataSetElement>;

        /*! @brief データパターン : ≪リテラル式≫を指定する */
        static auto pattern_by_basic_literal()
            -> std::vector<GroupedExpressionDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -------------------------------------------
     * |     | GroupedExpression                 |
     * |=====|===================================|
     * |  _0 | -                                 |
     * -------------------------------------------
     *
     * -------------------------------------------
     * |     | GroupedExpression                 |
     * |     |-----------------------------------|
     * |     | expression (IdentifierExpression) |
     * |=====|===================================|
     * |  _1 | -                                 |
     * |-----|-----------------------------------|
     * |  _2 | o                                 |
     * -------------------------------------------
     *
     * -------------------------------------------
     * |     | GroupedExpression                 |
     * |     |-----------------------------------|
     * |     | expression (BasicLiteral)         |
     * |     |-----------------------------------|
     * |     | Type       | value                |
     * |=====|============|======================|
     * |  _3 | Null       | -                    |
     * |-----|            |----------------------|
     * |  _4 |            | o                    |
     * |-----|------------|----------------------|
     * |  _5 | Boolean    | -                    |
     * |-----|            |----------------------|
     * |  _6 |            | o (true)             |
     * |-----|            |----------------------|
     * |  _7 |            | o (false)            |
     * |-----|------------|----------------------|
     * |  _8 | Integer    | -                    |
     * |-----|            |----------------------|
     * |  _9 |            | o (MIN - 1)          |
     * |-----|            |----------------------|
     * | _10 |            | o (MIN)              |
     * |-----|            |----------------------|
     * | _11 |            | o (-1)               |
     * |-----|            |----------------------|
     * | _12 |            | o (0)                |
     * |-----|            |----------------------|
     * | _13 |            | o (+1)               |
     * |-----|            |----------------------|
     * | _14 |            | o (MAX)              |
     * |-----|            |----------------------|
     * | _15 |            | o (MAX + 1)          |
     * |-----|-----------------------------------|
     * | _16 | RealNumber | -                    |
     * |-----|            |----------------------|
     * | _17 |            | o (MIN - 0.1E+38)    |
     * |-----|            |----------------------|
     * | _18 |            | o (MIN)              |
     * |-----|            |----------------------|
     * | _19 |            | o (-0.1)             |
     * |-----|            |----------------------|
     * | _20 |            | o (0.0)              |
     * |-----|            |----------------------|
     * | _21 |            | o (+0.1)             |
     * |-----|            |----------------------|
     * | _22 |            | o (MAX)              |
     * |-----|            |----------------------|
     * | _23 |            | o (MAX + 0.1E+38)    |
     * |-----|-----------------------------------|
     * | _24 | String     | -                    |
     * |-----|            |----------------------|
     * | _25 |            | o (empty-string)     |
     * |-----|            |----------------------|
     * | _26 |            | o (white-space)      |
     * |-----|            |----------------------|
     * | _27 |            | o (any-string)       |
     * -------------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -            ... 未指定
     * @li o            ... 指定
     * @li MIN          ... 内部値の型（ @c int または @c float ）の最小値
     * @li MAX          ... 内部値の型（ @c int または @c float ）の最大値
     * @li empty-string ... 空文字列
     * @li white-space  ... 半角スペース
     * @li any-string   ... 任意の文字列
     *
     * [ 構成 ] @n
     * @li _0       : @link pattern_by_default_construction()  @endlink
     * @li _1 ~  _2 : @link pattern_by_identifier_expression() @endlink
     * @li _3 ~ _27 : @link pattern_by_basic_literal()         @endlink
     *
     * @return ≪グループ化された式≫のテストケースで使用するデータセット
     */
    auto GroupedExpressionDataSet::for_some_test_case()
        -> std::vector<GroupedExpressionDataSetElement>
    {
        std::vector<std::vector<GroupedExpressionDataSetElement>>
            data_set_parts = {
                // clang-format off
                GroupedExpressionDataSet::pattern_by_default_construction(),
                GroupedExpressionDataSet::pattern_by_identifier_expression(),
                GroupedExpressionDataSet::pattern_by_basic_literal(),
                // clang-format on
            };

        auto data_set = std::vector<GroupedExpressionDataSetElement>();
        for (auto && data_set_part : data_set_parts) {
            data_set.insert(
                std::end(data_set),
                std::begin(data_set_part),
                std::end(data_set_part));
        }
        return data_set;
    }

    /*!
     * [ データパターン ] @n
     * @c GroupedExpression : デフォルトコンストラクタによりオブジェクトを構築する
     *
     * @return ≪グループ化された式≫のテストケースで使用するデータセット
     */
    auto GroupedExpressionDataSet::pattern_by_default_construction()
        -> std::vector<GroupedExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {},

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c GroupedExpression @n
     * @li @c expression : ≪識別子式≫
     *
     * @return ≪グループ化された式≫のテストケースで使用するデータセット
     */
    auto GroupedExpressionDataSet::pattern_by_identifier_expression()
        -> std::vector<GroupedExpressionDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪識別子式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IdentifierExpression { },
                },

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                ""
            },
            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪識別子式≫
            //         + value : 指定（テーブル名（エイリアス名） + カラム名）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IdentifierExpression { "p.id" },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(p.id)",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c GroupedExpression @n
     * @li @c expression : 各種≪リテラル式≫
     *
     * @return ≪グループ化された式≫のテストケースで使用するデータセット
     */
    auto GroupedExpressionDataSet::pattern_by_basic_literal()
        -> std::vector<GroupedExpressionDataSetElement>
    {
        // clang-format off
        return {
            ////////////////////////////////////////////////////////////////////
            // ≪NULLリテラル式≫
            ////////////////////////////////////////////////////////////////////

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪NULLリテラル式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    NullLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(NULL)",
            },
            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪NULLリテラル式≫
            //         + value : null-pointer
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    NullLiteral { nullptr },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(NULL)",
            },

            ////////////////////////////////////////////////////////////////////
            // ≪論理値リテラル式≫
            ////////////////////////////////////////////////////////////////////

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪論理値リテラル式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    BooleanLiteral { },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(FALSE)",
            },
            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪論理値リテラル式≫
            //         + value : 真
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    BooleanLiteral { true },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(TRUE)",
            },
            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪論理値リテラル式≫
            //         + value : 偽
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    BooleanLiteral { false },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(FALSE)",
            },

            ////////////////////////////////////////////////////////////////////
            // ≪整数リテラル式≫
            ////////////////////////////////////////////////////////////////////

            // _8
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(0)",
            },
            // _9
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : -2,147,483,649 （ int 型の最小値 - 1 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { std::numeric_limits<int>::min() - 1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(2147483647)",
            },
            // _10
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : -2,147,483,648 （ int 型の最小値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { std::numeric_limits<int>::min() },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(-2147483648)",
            },
            // _11
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : -1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { -1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(-1)",
            },
            // _12
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : 0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { 0 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(0)",
            },
            // _13
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : 1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { 1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(1)",
            },
            // _14
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : +2,147,483,647 （ int 型の最大値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { std::numeric_limits<int>::max() },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(2147483647)",
            },
            // _15
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪整数リテラル式≫
            //         + value : +2,147,483,648 （ int 型の最大値 + 1 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    IntegerLiteral { std::numeric_limits<int>::max() + 1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(-2147483648)",
            },

            ////////////////////////////////////////////////////////////////////
            // ≪実数リテラル式≫
            ////////////////////////////////////////////////////////////////////

            // _16
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral { },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(0.000000)",
            },
            // _17
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : -3.402823466E+38 - 0.1E+38 （ float 型の最小値 - 0.1E+38 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral {
                        // NOTE std::numeric_limits<float>::min() は非ゼロの正の値の最小値を返すため、
                        //      代わりに lowest() を使用する。
                        std::numeric_limits<float>::lowest() - 0.1e38f,
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                // NOTE 浮動小数点数のオーバーフローが発生し、値は負の無限大になる。
                "(-inf)",
            },
            // _18
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : -3.402823466E+38 （ float 型の最小値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral {
                        // NOTE std::numeric_limits<float>::min() は非ゼロの正の値の最小値を返すため、
                        //      代わりに lowest() を使用する。
                        std::numeric_limits<float>::lowest(),
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(-340282346638528859811704183484516925440.000000)",
            },
            // _19
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : -0.1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral { -0.1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(-0.100000)",
            },
            // _20
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : 0.0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral { 0.0f },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(0.000000)",
            },
            // _21
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : +0.1
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral { 0.1 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(0.100000)",
            },
            // _22
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : +3.402823466E+38 （ float 型の最大値）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral {
                        std::numeric_limits<float>::max(),
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(340282346638528859811704183484516925440.000000)",
            },
            // _23
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪実数リテラル式≫
            //         + value : +3.402823466E+38 + 0.1E+38 （ float 型の最大値 + 0.1E+38 ）
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    RealNumberLiteral {
                        std::numeric_limits<float>::max() + 0.1e38f,
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                // NOTE 浮動小数点数のオーバーフローが発生し、値は正の無限大になる。
                "(inf)",
            },

            ////////////////////////////////////////////////////////////////////
            // ≪文字列リテラル式≫
            ////////////////////////////////////////////////////////////////////

            // _24
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪文字列リテラル式≫
            //         + value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    StringLiteral { },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "('')",
            },
            // _25
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪文字列リテラル式≫
            //         + value : 空文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    StringLiteral { "" },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "('')",
            },
            // _26
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪文字列リテラル式≫
            //         + value : 半角スペース
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    StringLiteral { " " },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(' ')",
            },
            // _27
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + GroupedExpression
            //     + expression
            //         + Type  : ≪文字列リテラル式≫
            //         + value : 任意の文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                GroupedExpression {
                    StringLiteral { "This is a test string." },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "('This is a test string.')",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__GROUPED_EXPRESSION_DATA_SET_HXX */
