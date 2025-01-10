/*!
 * @file binary-operation-data-set.class-member.02.pattern_by_logical_operation.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX

#include <iterator>
#include <vector>

#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>

#include "../binary-operation-data-set-element.class.h++"

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
     * |     | BinaryOperation                |
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
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_logical_operation()
        -> std::vector<BinaryOperationDataSetElement>
    {
        std::vector<std::vector<BinaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                BinaryOperationDataSet::pattern_by_logical_and(),
                BinaryOperationDataSet::pattern_by_logical_or(),
                // clang-format on
            };

        auto data_set = std::vector<BinaryOperationDataSetElement>();
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
     * @c BinaryOperation @n
     * @li @c operater : ≪論理積演算≫ ( @c logical_and )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_logical_and()
        -> std::vector<BinaryOperationDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _37
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperation
            //     + operater : ≪論理積演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalAnd,
                    new BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        new IdentifierExpression { "p.birth_day" },
                        new StringLiteral { "1901-01-01" },
                    },
                    new BinaryOperation {
                        BinaryOperationKind::LessEqual,
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
            // + BinaryOperation
            //     + operater : ≪論理積演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalAnd,
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
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
            // + BinaryOperation
            //     + operater : ≪論理積演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalAnd,
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
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
            // + BinaryOperation
            //     + operater : ≪論理積演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalAnd,
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            new BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "John Doe" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::EqualTo,
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
     * @c BinaryOperation @n
     * @li @c operater : ≪論理和演算≫ ( @c logical_or )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto BinaryOperationDataSet::pattern_by_logical_or()
        -> std::vector<BinaryOperationDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _41
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + BinaryOperation
            //     + operater : ≪論理和演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalOr,
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
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
            // + BinaryOperation
            //     + operater : ≪論理和演算≫
            //     + left     : ≪条件式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalOr,
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        new IdentifierExpression { "p.name" },
                        new StringLiteral { "John Doe" },
                    },
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
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
            // + BinaryOperation
            //     + operater : ≪論理和演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalOr,
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new BinaryOperation {
                        BinaryOperationKind::EqualTo,
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
            // + BinaryOperation
            //     + operater : ≪論理和演算≫
            //     + left     : ≪グループ化された式≫
            //     + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                BinaryOperation {
                    BinaryOperationKind::LogicalOr,
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            new BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "1901-01-01" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::LessEqual,
                                new IdentifierExpression { "p.birth_day" },
                                new StringLiteral { "2000-12-31" },
                            },
                        },
                    },
                    new GroupedExpression {
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            new BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                new IdentifierExpression { "p.name" },
                                new StringLiteral { "John Doe" },
                            },
                            new BinaryOperation {
                                BinaryOperationKind::EqualTo,
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

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__OPERATION__DATA_SET__BINARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX */
