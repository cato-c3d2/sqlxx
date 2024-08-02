/*!
 * @file select-statement-data-set.class-member.05-with-where-clause.02.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_02_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_02_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/operation-kind.enum-class.h++>
#include <sql++/identifier/column-identifier.class.h++>
#include <sql++/identifier/table-identifier.class.h++>
#include <sql++/statement/select-statement.class.h++>

#include "../select-statement-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace statement
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターン表 ] @n
     * <pre>
     * -----------------------------------------
     * |      | WhereClause                    |
     * |      |--------------------------------|
     * |      | condition_expression           |
     * |      |--------------------------------|
     * |      | operater | left     | right    |
     * |======|==========|==========|==========|
     * | _107 | AND      | CE       | CE       |
     * |------|          |          |----------|
     * | _108 |          |          | GE       |
     * |------|          |----------|----------|
     * | _109 |          | GE       | CE       |
     * |------|          |          |----------|
     * | _110 |          |          | GE       |
     * |------|----------|----------|----------|
     * | _111 | OR       | CE       | CE       |
     * |------|          |          |----------|
     * | _112 |          |          | GE       |
     * |------|          |----------|----------|
     * | _113 |          | GE       | CE       |
     * |------|          |          |----------|
     * | _114 |          |          | GE       |
     * -----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li AND ... ≪論理積演算≫ ( @c logical_and )
     * @li OR  ... ≪論理和演算≫ ( @c logical_or )
     * @li CE  ... ≪条件式≫ ( @c ConditionExpression )
     * @li GE  ... ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * [ 構成 ] @n
     * @li _107 ~ _110 : @link with_where_clause_and_logical_and() @endlink
     * @li _111 ~ _114 : @link with_where_clause_and_logical_or()  @endlink
     *
     * [ 備考 ] @n
     * @c SelectClause 及び @c FromClause は各データパターンにおいて共通のものを使用する（下記参照）。 @n
     *
     * @c SelectClause @n
     * @li @c columns[0] : 下記参照
     * @li @c columns[1] : 下記参照
     *
     * @c columns[0] @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @c columns[1] @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @c FromClause @n
     * @li @c table : 下記参照
     *
     * @c table @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_logical_operation()
        -> std::vector<SelectStatementDataSetElement>
    {
        std::vector<std::vector<SelectStatementDataSetElement>>
            data_set_parts = {
                // clang-format off
                SelectStatementDataSet::with_where_clause_and_logical_and(),
                SelectStatementDataSet::with_where_clause_and_logical_or(),
                // clang-format on
            };

        auto data_set = std::vector<SelectStatementDataSetElement>();
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
     * @c WhereClause @n
     * @li @c condition_expression : 下記参照
     *
     * @c condition_expression @n
     * @li @c operater : ≪論理積演算≫ ( @c logical_and )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_logical_and()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _107
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理積演算≫
            //         + left     : ≪条件式≫
            //         + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //         .logical_and(
                //             IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31'",
            },

            // _108
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理積演算≫
            //         + left     : ≪条件式≫
            //         + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //         .logical_and(
                //             sqlxx::parentheses(
                //                 IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //                 .logical_and(
                //                     IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //                 )
                //             )
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.name = 'John Doe'"
                " AND (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')",
            },

            // _109
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理積演算≫
            //         + left     : ≪グループ化された式≫
            //         + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         sqlxx::parentheses(
                //             IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //             .logical_and(
                //                 IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //             )
                //         )
                //         .logical_and(
                //             IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')"
                " AND p.name = 'John Doe'",
            },

            // _110
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理積演算≫
            //         + left     : ≪グループ化された式≫
            //         + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         sqlxx::parentheses(
                //             IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //             .logical_and(
                //                 IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //             )
                //         )
                //         .logical_and(
                //             sqlxx::parentheses(
                //                 IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //                 .logical_or(
                //                     IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                //                 )
                //             )
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')"
                " AND (p.name = 'John Doe' OR p.name = 'Jane Doe')",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : 下記参照
     *
     * @c condition_expression @n
     * @li @c operater : ≪論理和演算≫ ( @c logical_or )
     * @li @c left     : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     * @li @c right    : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_logical_or()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _111
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理和演算≫
            //         + left     : ≪条件式≫
            //         + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //         .logical_or(
                //             IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.name = 'John Doe' OR p.name = 'Jane Doe'",
            },

            // _112
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理和演算≫
            //         + left     : ≪条件式≫
            //         + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     WhereClause {
                //         IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //         .logical_or(
                //             sqlxx::parentheses(
                //                 IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //                 .logical_and(
                //                     IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //                 )
                //             )
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.name = 'John Doe'"
                " OR (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')",
            },

            // _113
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理和演算≫
            //         + left     : ≪グループ化された式≫
            //         + right    : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     // FIXME [要不具合修正] コンパイルエラーが発生する。
                //     //       GroupedExpression クラスに logical_and メンバ関数及び logical_or メンバ関数を実装すること。
                //     WhereClause {
                //         sqlxx::parentheses(
                //             IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //             .logical_and(
                //                 IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //             )
                //         )
                //         .logical_or(
                //             IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')"
                " OR p.name = 'John Doe'",
            },

            // _114
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + condition_expression
            //         + operater : ≪論理和演算≫
            //         + left     : ≪グループ化された式≫
            //         + right    : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                SelectStatement {
                    SelectClause {{
                        ColumnIdentifier { "id" }.as({ "p.id" }),
                        ColumnIdentifier { "name" }.as({ "p.name" }),
                    }},
                    FromClause {
                        TableIdentifier { "people" }.as({ "p" }),
                    },
                    WhereClause {
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
                    },
                },

                // テスト対象オブジェクト - DSL記法
                // TODO [要修正] DSL 記法のテストを実施すること。
                // SelectStatement {
                //     SelectClause {{
                //         ColumnIdentifier { "id" }.as({ "p.id" }),
                //         ColumnIdentifier { "name" }.as({ "p.name" }),
                //     }},
                //     FromClause {
                //         TableIdentifier { "people" }.as({ "p" }),
                //     },
                //     // FIXME [要不具合修正] コンパイルエラーが発生する。
                //     //       GroupedExpression クラスに logical_and メンバ関数及び logical_or メンバ関数を実装すること。
                //     WhereClause {
                //         sqlxx::parentheses(
                //             IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                //             .logical_and(
                //                 IdentifierExpression { "p.birth_day" }.less_equal("2000-12-31"s)
                //             )
                //         )
                //         .logical_or(
                //             sqlxx::parentheses(
                //                 IdentifierExpression { "p.name" }.equal_to("John Doe"s)
                //                 .logical_or(
                //                     IdentifierExpression { "p.name" }.equal_to("Jane Doe"s)
                //                 )
                //             )
                //         ),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')"
                " OR (p.name = 'John Doe' OR p.name = 'Jane Doe')",
            },
        };
        // clang-format on
    }
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_02_HXX */
