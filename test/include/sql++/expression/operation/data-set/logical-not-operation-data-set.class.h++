/*!
 * @file logical-not-operation-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_NOT_OPERATION_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_NOT_OPERATION_DATA_SET_HXX

#include <limits>
#include <vector>

#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/boolean-literal.class.h++>
#include <sql++/expression/literal/integer-literal.class.h++>
#include <sql++/expression/literal/null-literal.class.h++>
#include <sql++/expression/literal/real-number-literal.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
#include <sql++/expression/operation/logical-not-operation.class.h++>
#include <sql++/expression/operation/operation-kind.enum-class.h++>

#include "./logical-not-operation-data-set-element.class.h++"

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
     * @brief ≪論理否定演算式≫のテストケースで使用するデータセットを生成するクラス
     *
     * @see sqlxx::expression::LogicalNotOperation              テスト対象クラス
     * @see sqlxx::test::expression::LogicalNotOperationDataSet データセット要素
     */
    class LogicalNotOperationDataSet
    {
    public:
        /*! @brief ≪論理否定演算式≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<LogicalNotOperationDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪NULLリテラル式≫を指定する */
        static auto pattern_by_null_literal_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪論理値リテラル式≫を指定する */
        static auto pattern_by_boolean_literal_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪整数リテラル式≫を指定する */
        static auto pattern_by_integer_literal_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪実数リテラル式≫を指定する */
        static auto pattern_by_real_number_literal_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪文字列リテラル式≫を指定する */
        static auto pattern_by_string_literal_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪条件式≫を指定する */
        static auto pattern_by_condition_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;

        /*! @brief データパターン : ≪グループ化された式≫を指定する */
        static auto pattern_by_grouped_expression()
            -> std::vector<LogicalNotOperationDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ----------------------------------------------------
     * |     | LogicalNotOperation                        |
     * |     |--------------------------------------------|
     * |     | expression                                 |
     * |=====|============================================|
     * |  _0 | -                                          |
     * ----------------------------------------------------
     *
     * ----------------------------------------------------
     * |     | LogicalNotOperation                        |
     * |     |--------------------------------------------|
     * |     | expression                                 |
     * |     |--------------------------------------------|
     * |     | Type                | expression           |
     * |=====|=====================|======================|
     * |  _1 | NullLiteral         | -                    |
     * |-----|                     |----------------------|
     * |  _2 |                     | o (null-pointer)     |
     * |-----|---------------------|----------------------|
     * |  _3 | BooleanLiteral      | -                    |
     * |-----|                     |----------------------|
     * |  _4 |                     | o (false)            |
     * |-----|                     |----------------------|
     * |  _5 |                     | o (true)             |
     * |-----|---------------------|----------------------|
     * |  _6 | IntegerLiteral      | -                    |
     * |-----|                     |----------------------|
     * |  _7 |                     | o (0)                |
     * |-----|                     |----------------------|
     * |  _8 |                     | o (MIN)              |
     * |-----|                     |----------------------|
     * |  _9 |                     | o (MAX)              |
     * |-----|---------------------|----------------------|
     * | _10 | RealNumberLiteral   | -                    |
     * |-----|                     |----------------------|
     * | _11 |                     | o (0.0)              |
     * |-----|                     |----------------------|
     * | _12 |                     | o (MIN)              |
     * |-----|                     |----------------------|
     * | _13 |                     | o (MAX)              |
     * |-----|---------------------|----------------------|
     * | _14 | StringLiteral       | -                    |
     * |-----|                     |----------------------|
     * | _15 |                     | o (empty-string)     |
     * |-----|                     |----------------------|
     * | _16 |                     | o (white-space)      |
     * |-----|                     |----------------------|
     * | _17 |                     | o (any-string)       |
     * ----------------------------------------------------
     *
     * ----------------------------------------------------
     * |     | LogicalNotOperation                        |
     * |     |--------------------------------------------|
     * |     | expression                                 |
     * |     |--------------------------------------------|
     * |     | Type                | expression           |
     * |=====|=====================|======================|
     * | _18 | ConditionExpression | -                    |
     * |-----|                     |----------------------|
     * | _19 |                     | o (one-expression)   |
     * |-----|                     |----------------------|
     * | _20 |                     | o (some-expressions) |
     * |-----|---------------------|----------------------|
     * | _21 | GroupedExpression   | -                    |
     * |-----|                     |----------------------|
     * | _22 |                     | o (one-expression)   |
     * |-----|                     |----------------------|
     * | _23 |                     | o (some-expressions) |
     * ----------------------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li -                ... 未指定
     * @li o                ... 指定
     * @li MIN              ... 内部値の型( @c int または @c float )の最小値
     * @li MAX              ... 内部値の型( @c int または @c float )の最大値
     * @li empty-string     ... 空文字列
     * @li white-space      ... 半角スペース
     * @li any-string       ... 任意の文字列
     * @li one-expression   ... 単一の式
     * @li some-expressions ... 複数の式
     *
     * [ 構成 ] @n
     * @li        _0 : @link pattern_by_default_construction()           @endlink
     * @li  _1 ~  _2 : @link pattern_by_null_literal_expression()        @endlink
     * @li  _3 ~  _5 : @link pattern_by_boolean_literal_expression()     @endlink
     * @li  _6 ~  _9 : @link pattern_by_integer_literal_expression()     @endlink
     * @li _10 ~ _13 : @link pattern_by_real_number_literal_expression() @endlink
     * @li _14 ~ _17 : @link pattern_by_string_literal_expression()      @endlink
     * @li _18 ~ _20 : @link pattern_by_condition_expression()           @endlink
     * @li _21 ~ _23 : @link pattern_by_grouped_expression()             @endlink
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     *
     * @see sqlxx::expression::LogicalNotOperation::empty()     テスト対象メンバ関数
     * @see sqlxx::expression::LogicalNotOperation::to_string() テスト対象メンバ関数
     */
    auto LogicalNotOperationDataSet::for_some_test_case()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        std::vector<std::vector<LogicalNotOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                LogicalNotOperationDataSet::pattern_by_default_construction(),
                LogicalNotOperationDataSet::pattern_by_null_literal_expression(),
                LogicalNotOperationDataSet::pattern_by_boolean_literal_expression(),
                LogicalNotOperationDataSet::pattern_by_integer_literal_expression(),
                LogicalNotOperationDataSet::pattern_by_real_number_literal_expression(),
                LogicalNotOperationDataSet::pattern_by_string_literal_expression(),
                LogicalNotOperationDataSet::pattern_by_condition_expression(),
                LogicalNotOperationDataSet::pattern_by_grouped_expression(),
                // clang-format on
            };

        auto data_set = std::vector<LogicalNotOperationDataSetElement>();
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
     * @c LogicalNotOperation : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_default_construction()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {},

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
     * @c LogicalNotOperation @n
     * @li @c expression : ≪NULLリテラル式≫ ( @c NullLiteral )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_null_literal_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪NULLリテラル式≫
            //         + inner_value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    NullLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT NULL",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪NULLリテラル式≫
            //         + inner_value : null-pointer
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    NullLiteral { nullptr },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT NULL",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : ≪論理値リテラル式≫ ( @c BooleanLiteral )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_boolean_literal_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪論理値リテラル式≫
            //         + inner_value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BooleanLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT FALSE",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪論理値リテラル式≫
            //         + inner_value : 偽
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BooleanLiteral { false },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT FALSE",
            },

            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪論理値リテラル式≫
            //         + inner_value : 真
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BooleanLiteral { true },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT TRUE",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : ≪整数リテラル式≫ ( @c IntegerLiteral )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_integer_literal_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪整数リテラル式≫
            //         + inner_value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    IntegerLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 0",
            },

            // _7
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪整数リテラル式≫
            //         + inner_value : 0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    IntegerLiteral { 0 },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 0",
            },

            // _8
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪整数リテラル式≫
            //         + inner_value : -2,147,483,648 (int 型の最小値)
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    IntegerLiteral { std::numeric_limits<int>::min() },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT -2147483648",
            },

            // _9
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪整数リテラル式≫
            //         + inner_value : +2,147,483,647 (int 型の最大値)
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    IntegerLiteral { std::numeric_limits<int>::max() },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 2147483647",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : ≪実数リテラル式≫ ( @c RealNumberLiteral )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_real_number_literal_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _10
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪実数リテラル式≫
            //         + inner_value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    RealNumberLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 0.000000",
            },

            // _11
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪実数リテラル式≫
            //         + inner_value : 0.0
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    RealNumberLiteral { 0.0f },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 0.000000",
            },

            // _12
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪実数リテラル式≫
            //         + inner_value : -3.402823466E+38 (float 型の最小値)
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    RealNumberLiteral {
                        // NOTE std::numeric_limits<float>::min() は非ゼロの正の値の最小値を返すため、
                        //      代わりに lowest() を使用する。
                        std::numeric_limits<float>::lowest(),
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT -340282346638528859811704183484516925440.000000",
            },

            // _13
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪実数リテラル式≫
            //         + inner_value : +3.402823466E+38 (float 型の最大値)
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    RealNumberLiteral {
                        std::numeric_limits<float>::max(),
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 340282346638528859811704183484516925440.000000",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : ≪文字列リテラル式≫ ( @c StringLiteral )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_string_literal_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _14
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪文字列リテラル式≫
            //         + inner_value : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    StringLiteral {},
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT ''",
            },

            // _15
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪文字列リテラル式≫
            //         + inner_value : 空文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    StringLiteral { "" },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT ''",
            },

            // _16
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪文字列リテラル式≫
            //         + inner_value : 半角スペース
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    StringLiteral { " " },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT ' '",
            },

            // _17
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type        : ≪文字列リテラル式≫
            //         + inner_value : 任意の文字列
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    StringLiteral { "This is a test string." },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT 'This is a test string.'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : ≪条件式≫(≪二項演算式≫( @c BinaryOperation ))
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_condition_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _18
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : 条件式
            //         + expression : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BinaryOperation {},
                },

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _19
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : 条件式
            //         + expression : 単一の式
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BinaryOperation {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.id" },
                        new IntegerLiteral { 1234 },
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT p.id = 1234",
            },

            // _20
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : 条件式
            //         + expression : 複数の式
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    BinaryOperation {
                        OperationKind::LogicalAnd,
                        new BinaryOperation {
                            OperationKind::EqualTo,
                            new IdentifierExpression { "p.name" },
                            new StringLiteral { "John Doe" },
                        },
                        new BinaryOperation {
                            OperationKind::LessEqual,
                            new IdentifierExpression { "p.birth_day" },
                            new StringLiteral { "2000-12-31" },
                        },
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT p.name = 'John Doe' AND p.birth_day <= '2000-12-31'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c LogicalNotOperation @n
     * @li @c expression : グループ化された式 ( @c GroupedExpression )
     *
     * @return ≪論理否定演算式≫のテストケースで使用するデータセット
     */
    auto LogicalNotOperationDataSet::pattern_by_grouped_expression()
        -> std::vector<LogicalNotOperationDataSetElement>
    {
        // clang-format off
        return {
            // _21
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : グループ化された式
            //         + expression : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    GroupedExpression {},
                },

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _22
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : グループ化された式
            //         + expression : 単一の式
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    GroupedExpression {
                        BinaryOperation {
                            OperationKind::EqualTo,
                            new IdentifierExpression { "p.id" },
                            new IntegerLiteral { 1234 },
                        },
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT (p.id = 1234)",
            },

            // _23
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + LogicalNotOperation
            //     + expression
            //         + Type       : グループ化された式
            //         + expression : 複数の式
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト
                LogicalNotOperation {
                    GroupedExpression {
                        BinaryOperation {
                            OperationKind::LogicalAnd,
                            new BinaryOperation {
                                OperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "John Doe" },
                            },
                            new BinaryOperation {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT (p.name = 'John Doe' AND p.birth_day <= '2000-12-31')",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__LOGICAL_NOT_OPERATION_DATA_SET_HXX */
