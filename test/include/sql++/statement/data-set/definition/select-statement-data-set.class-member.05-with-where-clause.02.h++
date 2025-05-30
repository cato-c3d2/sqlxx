/*!
 * @file select-statement-data-set.class-member.05-with-where-clause.02.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_02_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_02_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
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
     * |      | BinaryOperation                |
     * |      |--------------------------------|
     * |      | operator | left     | right    |
     * |======|==========|==========|==========|
     * | _105 | AND      | CE       | CE       |
     * |------|          |          |----------|
     * | _106 |          |          | GE       |
     * |------|          |----------|----------|
     * | _107 |          | GE       | CE       |
     * |------|          |          |----------|
     * | _108 |          |          | GE       |
     * |------|----------|----------|----------|
     * | _109 | OR       | CE       | CE       |
     * |------|          |          |----------|
     * | _110 |          |          | GE       |
     * |------|          |----------|----------|
     * | _111 |          | GE       | CE       |
     * |------|          |          |----------|
     * | _112 |          |          | GE       |
     * -----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li AND : ≪論理積演算≫（ @c logical_and ）
     * @li OR  : ≪論理和演算≫（ @c logical_or ）
     * @li CE  : ≪条件式≫（ @c ConditionExpression ）
     * @li GE  : ≪グループ化された式≫（ @c GroupedExpression ）
     *
     * [ 構成 ] @n
     * @li _105 ~ _108 : @link with_where_clause_and_logical_and() @endlink
     * @li _109 ~ _112 : @link with_where_clause_and_logical_or()  @endlink
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
     * @li @c condition_expression : @c BinaryOperation （下記参照）
     *
     * @c BinaryOperation @n
     * @li @c operator : ≪論理積演算≫（ @c logical_and ）
     * @li @c left     : ≪条件式≫（ @c ConditionExpression ） or
     *                   ≪グループ化された式≫（ @c GroupedExpression ）
     * @li @c right    : ≪条件式≫（ @c ConditionExpression ） or
     *                   ≪グループ化された式≫（ @c GroupedExpression ）
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_logical_and()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _105
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理積演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            BinaryOperation {
                                BinaryOperationKind::GreaterEqual,
                                IdentifierExpression { "p.birth_day" },
                                StringLiteral { "1901-01-01" },
                            },
                            BinaryOperation {
                                BinaryOperationKind::LessEqual,
                                IdentifierExpression { "p.birth_day" },
                                StringLiteral { "2000-12-31" },
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

            // _106
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理積演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "John Doe" },
                            },
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
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

            // _107
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理積演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
                                    },
                                },
                            },
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "John Doe" },
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

            // _108
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理積演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalAnd,
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
                                    },
                                },
                            },
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalOr,
                                    BinaryOperation {
                                        BinaryOperationKind::EqualTo,
                                        IdentifierExpression { "p.name" },
                                        StringLiteral { "John Doe" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::EqualTo,
                                        IdentifierExpression { "p.name" },
                                        StringLiteral { "Jane Doe" },
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
     * @li @c condition_expression : @c BinaryOperation （下記参照）
     *
     * @c BinaryOperation @n
     * @li @c operator : ≪論理和演算≫（ @c logical_or ）
     * @li @c left     : ≪条件式≫（ @c ConditionExpression ） or
     *                   ≪グループ化された式≫（ @c GroupedExpression ）
     * @li @c right    : ≪条件式≫（ @c ConditionExpression ） or
     *                   ≪グループ化された式≫（ @c GroupedExpression ）
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_logical_or()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _109
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理和演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "John Doe" },
                            },
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "Jane Doe" },
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

            // _110
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理和演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "John Doe" },
                            },
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
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

            // _111
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理和演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
                                    },
                                },
                            },
                            BinaryOperation {
                                BinaryOperationKind::EqualTo,
                                IdentifierExpression { "p.name" },
                                StringLiteral { "John Doe" },
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

            // _112
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operator : ≪論理和演算≫
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
                        BinaryOperation {
                            BinaryOperationKind::LogicalOr,
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalAnd,
                                    BinaryOperation {
                                        BinaryOperationKind::GreaterEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "1901-01-01" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::LessEqual,
                                        IdentifierExpression { "p.birth_day" },
                                        StringLiteral { "2000-12-31" },
                                    },
                                },
                            },
                            GroupedExpression {
                                BinaryOperation {
                                    BinaryOperationKind::LogicalOr,
                                    BinaryOperation {
                                        BinaryOperationKind::EqualTo,
                                        IdentifierExpression { "p.name" },
                                        StringLiteral { "John Doe" },
                                    },
                                    BinaryOperation {
                                        BinaryOperationKind::EqualTo,
                                        IdentifierExpression { "p.name" },
                                        StringLiteral { "Jane Doe" },
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
