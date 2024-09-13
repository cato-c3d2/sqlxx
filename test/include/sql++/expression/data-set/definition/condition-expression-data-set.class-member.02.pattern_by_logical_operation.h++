/*!
 * @file condition-expression-data-set.class-member.02.pattern_by_logical_operation.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX

#include <iterator>
#include <vector>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/operation-kind.enum-class.h++>

#include "../condition-expression-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * ----------------------------------------
     * |     | ConditionExpression            |
     * |     |--------------------------------|
     * |     | operater | left     | right    |
     * |=====|==========|==========|==========|
     * | _37 | AND      | CE       | CE       |
     * |-----|          |          |----------|
     * | _38 |          |          | GE       |
     * |-----|          |----------|----------|
     * | _39 |          | GE       | CE       |
     * |-----|          |          |----------|
     * | _40 |          |          | GE       |
     * |-----|----------|----------|----------|
     * | _41 | OR       | CE       | CE       |
     * |-----|          |          |----------|
     * | _42 |          |          | GE       |
     * |-----|          |----------|----------|
     * | _43 |          | GE       | CE       |
     * |-----|          |          |----------|
     * | _44 |          |          | GE       |
     * ----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li AND ... ≪論理積演算≫ ( @c logical_and )
     * @li OR  ... ≪論理和演算≫ ( @c logical_or )
     * @li CE  ... ≪条件式≫ ( @c ConditionExpression )
     * @li GE  ... ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * [ 構成 ] @n
     * @li _37 ~ _40 : @link pattern_by_logical_and() @endlink
     * @li _41 ~ _44 : @link pattern_by_logical_or()  @endlink
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_logical_operation()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        std::vector<std::vector<ConditionExpressionDataSetElement>>
            data_set_parts = {
                // clang-format off
                ConditionExpressionDataSet::pattern_by_logical_and(),
                ConditionExpressionDataSet::pattern_by_logical_or(),
                // clang-format on
            };

        auto data_set = std::vector<ConditionExpressionDataSetElement>();
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
     * @c ConditionExpression @n
     * @li @c operater : ≪論理積演算≫ ( @c logical_and )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_logical_and()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _37
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理積演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalAnd,
                    new ConditionExpression {
                        OperationKind::GreaterEqual,
                        new IdentifierExpression { "p.birth_day" },
                        new StringLiteral { "1901-01-01" },
                    },
                    new ConditionExpression {
                        OperationKind::LessEqual,
                        new IdentifierExpression { "p.birth_day" },
                        new StringLiteral { "2000-12-31" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                .logical_and(
                    IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31'",
            },

            // _38
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理積演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalAnd,
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                .logical_and(
                    sqlxx::parentheses(
                        IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                        .logical_and(
                            IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                        )
                    )
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name = 'John Doe' "
                    "AND (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')",
            },

            // _39
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理積演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalAnd,
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::parentheses(
                    IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                    .logical_and(
                        IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                    )
                )
                .logical_and(
                    IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31') "
                    "AND p.name = 'John Doe'",
            },

            // _40
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理積演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalAnd,
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalOr,
                            new ConditionExpression {
                                OperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "John Doe" },
                            },
                            new ConditionExpression {
                                OperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "Jane Doe" },
                            },
                        },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::parentheses(
                    IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                    .logical_and(
                        IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                    )
                )
                .logical_and(
                    sqlxx::parentheses(
                        IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                        .logical_or(
                            IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                        )
                    )
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31') "
                    "AND (p.name = 'John Doe' OR p.name = 'Jane Doe')",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪論理和演算≫ ( @c logical_or )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_logical_or()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _41
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理和演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalOr,
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "Jane Doe" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                .logical_or(
                    IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name = 'John Doe' OR p.name = 'Jane Doe'",
            },

            // _42
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理和演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalOr,
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                .logical_or(
                    sqlxx::parentheses(
                        IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                        .logical_and(
                            IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                        )
                    )
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name = 'John Doe' "
                    "OR (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')",
            },

            // _43
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理和演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalOr,
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new ConditionExpression {
                        OperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::parentheses(
                    IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                    .logical_and(
                        IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                    )
                )
                .logical_or(
                    IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31') "
                    "OR p.name = 'John Doe'",
            },

            // _44
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪論理和演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LogicalOr,
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalAnd,
                            new ConditionExpression {
                                OperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new ConditionExpression {
                                OperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new GroupedExpression {
                        ConditionExpression {
                            OperationKind::LogicalOr,
                            new ConditionExpression {
                                OperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "John Doe" },
                            },
                            new ConditionExpression {
                                OperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "Jane Doe" },
                            },
                        },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::parentheses(
                    IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                    .logical_and(
                        IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                    )
                )
                .logical_or(
                    sqlxx::parentheses(
                        IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                        .logical_or(
                            IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                        )
                    )
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "(p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31') "
                    "OR (p.name = 'John Doe' OR p.name = 'Jane Doe')",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX */
