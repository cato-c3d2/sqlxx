/*!
 * @file select-statement-data-set.class-member.05-with-where-clause.01.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_01_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_01_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
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
     * |      | BinaryOperation                |
     * |      |--------------------------------|
     * |      | operater | left     | right    |
     * |======|==========|==========|==========|
     * |  _79 | =        | IE       | IE       |
     * |------|          |          |----------|
     * |  _80 |          |          | LE       |
     * |------|          |----------|----------|
     * |  _81 |          | LE       | IE       |
     * |------|          |          |----------|
     * |  _82 |          |          | LE       |
     * |------|----------|----------|----------|
     * |  _83 | <>       | IE       | IE       |
     * |------|          |          |----------|
     * |  _84 |          |          | LE       |
     * |------|          |----------|----------|
     * |  _85 |          | LE       | IE       |
     * |------|          |          |----------|
     * |  _86 |          |          | LE       |
     * |------|----------|----------|----------|
     * |  _87 | <        | IE       | IE       |
     * |------|          |          |----------|
     * |  _88 |          |          | LE       |
     * |------|          |----------|----------|
     * |  _89 |          | LE       | IE       |
     * |------|          |          |----------|
     * |  _90 |          |          | LE       |
     * |------|----------|----------|----------|
     * |  _91 | <=       | IE       | IE       |
     * |------|          |          |----------|
     * |  _92 |          |          | LE       |
     * |------|          |----------|----------|
     * |  _93 |          | LE       | IE       |
     * |------|          |          |----------|
     * |  _94 |          |          | LE       |
     * |------|----------|----------|----------|
     * |  _95 | >        | IE       | IE       |
     * |------|          |          |----------|
     * |  _96 |          |          | LE       |
     * |------|          |----------|----------|
     * |  _97 |          | LE       | IE       |
     * |------|          |          |----------|
     * |  _98 |          |          | LE       |
     * |------|----------|----------|----------|
     * |  _99 | >=       | IE       | IE       |
     * |------|          |          |----------|
     * | _100 |          |          | LE       |
     * |------|          |----------|----------|
     * | _101 |          | LE       | IE       |
     * |------|          |          |----------|
     * | _102 |          |          | LE       |
     * |------|----------|----------|----------|
     * | _103 | IS       | IE       | IE       |
     * |------|          |          |----------|
     * | _104 |          |          | LE       |
     * |------|          |----------|----------|
     * | _105 |          | LE       | IE       |
     * |------|          |          |----------|
     * | _106 |          |          | LE       |
     * -----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li =  ... ≪等値比較演算≫ ( @c equal_to )
     * @li <> ... ≪非等値比較演算≫ ( @c not_equal_to )
     * @li <  ... ≪比較演算（小なり）≫ ( @c less )
     * @li <= ... ≪比較演算（以下）≫ ( @c less_equal )
     * @li >  ... ≪比較演算（大なり）≫ ( @c greater )
     * @li >= ... ≪比較演算（以上）≫ ( @c greater_equal )
     * @li IS ... ≪IS演算≫ ( @c is )
     * @li IE ... ≪識別子式≫ ( @c IdentifierExpression )
     * @li LE ... ≪リテラル式≫ ( @c BasicLiteral )
     *
     * [ 構成 ] @n
     * @li  _79 ~  _82 : @link with_where_clause_and_equal_to()      @endlink
     * @li  _83 ~  _86 : @link with_where_clause_and_not_equal_to()  @endlink
     * @li  _87 ~  _90 : @link with_where_clause_and_less()          @endlink
     * @li  _91 ~  _94 : @link with_where_clause_and_less_equal()    @endlink
     * @li  _95 ~  _98 : @link with_where_clause_and_greater()       @endlink
     * @li  _99 ~ _102 : @link with_where_clause_and_greater_equal() @endlink
     * @li _103 ~ _106 : @link with_where_clause_and_is()            @endlink
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
    auto SelectStatementDataSet::with_where_clause_and_comparison_operation()
        -> std::vector<SelectStatementDataSetElement>
    {
        std::vector<std::vector<SelectStatementDataSetElement>>
            data_set_parts = {
                // clang-format off
                SelectStatementDataSet::with_where_clause_and_equal_to(),
                SelectStatementDataSet::with_where_clause_and_not_equal_to(),
                SelectStatementDataSet::with_where_clause_and_less(),
                SelectStatementDataSet::with_where_clause_and_less_equal(),
                SelectStatementDataSet::with_where_clause_and_greater(),
                SelectStatementDataSet::with_where_clause_and_greater_equal(),
                SelectStatementDataSet::with_where_clause_and_is(),
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
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪等値比較演算≫ ( @c equal_to )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_equal_to()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _79
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪等値比較演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::EqualTo,
                            new IdentifierExpression { "p.name" },
                            new IdentifierExpression { "p.nickname" },
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
                //         IdentifierExpression { "p.name" }
                //         .equal_to(IdentifierExpression { "p.nickname" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.name = p.nickname",
            },

            // _80
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪等値比較演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::EqualTo,
                            new IdentifierExpression { "p.name" },
                            new StringLiteral { "John Doe" },
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
                //         IdentifierExpression { "p.name" }.equal_to("John Doe"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.name = 'John Doe'",
            },

            // _81
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪等値比較演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::EqualTo,
                            new StringLiteral { "John Doe" },
                            new IdentifierExpression { "p.name" },
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
                //         StringLiteral { "John Doe" }.equal_to(IdentifierExpression { "p.name" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE 'John Doe' = p.name",
            },

            // _82
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪等値比較演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::EqualTo,
                            new StringLiteral { "john doe" },
                            new StringLiteral { "JOHN DOE" },
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
                //         StringLiteral { "john doe" }.equal_to("JOHN DOE"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE 'john doe' = 'JOHN DOE'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪非等値比較演算≫ ( @c not_equal_to )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_not_equal_to()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _83
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪非等値比較演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::NotEqualTo,
                            new IdentifierExpression { "p.name" },
                            new IdentifierExpression { "p.nickname" },
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
                //         IdentifierExpression { "p.name" }
                //         .not_equal_to(IdentifierExpression { "p.nickname" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.name <> p.nickname",
            },

            // _84
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪非等値比較演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::NotEqualTo,
                            new IdentifierExpression { "p.name" },
                            new StringLiteral { "John Doe" },
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
                //         IdentifierExpression { "p.name" }.not_equal_to("John Doe"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.name <> 'John Doe'",
            },

            // _85
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪非等値比較演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::NotEqualTo,
                            new StringLiteral { "John Doe" },
                            new IdentifierExpression { "p.name" },
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
                //         StringLiteral { "John Doe" }
                //         .not_equal_to(IdentifierExpression { "p.name" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE 'John Doe' <> p.name",
            },

            // _86
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪非等値比較演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::NotEqualTo,
                            new StringLiteral { "john doe" },
                            new StringLiteral { "JOHN DOE" },
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
                //         StringLiteral { "john doe" }.not_equal_to("JOHN DOE"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE 'john doe' <> 'JOHN DOE'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪比較演算（小なり）≫ ( @c less )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_less()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _87
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（小なり）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Less,
                            new IdentifierExpression { "p.created_at" },
                            new IdentifierExpression { "p.updated_at" },
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
                //         IdentifierExpression { "p.created_at" }
                //         .less(IdentifierExpression { "p.updated_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at < p.updated_at",
            },

            // _88
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（小なり）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Less,
                            new IdentifierExpression { "p.created_at" },
                            new StringLiteral { "2001-01-01" },
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
                //         IdentifierExpression { "p.created_at" }.less("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at < '2001-01-01'",
            },

            // _89
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（小なり）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Less,
                            new StringLiteral { "2001-01-01" },
                            new IdentifierExpression { "p.created_at" },
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
                //         StringLiteral { "2001-01-01" }
                //         .less(IdentifierExpression { "p.created_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' < p.created_at",
            },

            // _90
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（小なり）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Less,
                            new StringLiteral { "2000-12-31" },
                            new StringLiteral { "2001-01-01" },
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
                //         StringLiteral { "2000-12-31" }.less("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2000-12-31' < '2001-01-01'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪比較演算（以下）≫ ( @c less_equal )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_less_equal()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _91
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以下）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::LessEqual,
                            new IdentifierExpression { "p.created_at" },
                            new IdentifierExpression { "p.updated_at" },
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
                //         IdentifierExpression { "p.created_at" }
                //         .less_equal(IdentifierExpression { "p.updated_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at <= p.updated_at",
            },

            // _92
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以下）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::LessEqual,
                            new IdentifierExpression { "p.created_at" },
                            new StringLiteral { "2001-01-01" },
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
                //         IdentifierExpression { "p.created_at" }.less_equal("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at <= '2001-01-01'",
            },

            // _93
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以下）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::LessEqual,
                            new StringLiteral { "2001-01-01" },
                            new IdentifierExpression { "p.created_at" },
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
                //         StringLiteral { "2001-01-01" }
                //         .less_equal(IdentifierExpression { "p.created_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' <= p.created_at",
            },

            // _94
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以下）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::LessEqual,
                            new StringLiteral { "2000-12-31" },
                            new StringLiteral { "2001-01-01" },
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
                //         StringLiteral { "2000-12-31" }.less_equal("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2000-12-31' <= '2001-01-01'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪比較演算（大なり）≫ ( @c greater )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_greater()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _95
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（大なり）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Greater,
                            new IdentifierExpression { "p.created_at" },
                            new IdentifierExpression { "p.updated_at" },
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
                //         IdentifierExpression { "p.created_at" }
                //         .greater(IdentifierExpression { "p.updated_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at > p.updated_at",
            },

            // _96
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（大なり）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Greater,
                            new IdentifierExpression { "p.created_at" },
                            new StringLiteral { "2001-01-01" },
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
                //         IdentifierExpression { "p.created_at" }.greater("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at > '2001-01-01'",
            },

            // _97
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（大なり）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Greater,
                            new StringLiteral { "2001-01-01" },
                            new IdentifierExpression { "p.created_at" },
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
                //         StringLiteral { "2001-01-01" }
                //         .greater(IdentifierExpression { "p.created_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' > p.created_at",
            },

            // _98
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（大なり）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Greater,
                            new StringLiteral { "2001-01-01" },
                            new StringLiteral { "2000-12-31" },
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
                //         StringLiteral { "2001-01-01" }.greater("2000-12-31"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' > '2000-12-31'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪比較演算（以上）≫ ( @c greater_equal )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_greater_equal()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _99
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以上）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::GreaterEqual,
                            new IdentifierExpression { "p.created_at" },
                            new IdentifierExpression { "p.updated_at" },
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
                //         IdentifierExpression { "p.created_at" }
                //         .greater_equal(IdentifierExpression { "p.updated_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at >= p.updated_at",
            },

            // _100
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以上）≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::GreaterEqual,
                            new IdentifierExpression { "p.created_at" },
                            new StringLiteral { "2001-01-01" },
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
                //         IdentifierExpression { "p.created_at" }.greater_equal("2001-01-01"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE p.created_at >= '2001-01-01'",
            },

            // _101
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以上）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::GreaterEqual,
                            new StringLiteral { "2001-01-01" },
                            new IdentifierExpression { "p.created_at" },
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
                //         StringLiteral { "2001-01-01" }
                //         .greater_equal(IdentifierExpression { "p.created_at" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' >= p.created_at",
            },

            // _102
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪比較演算（以上）≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::GreaterEqual,
                            new StringLiteral { "2001-01-01" },
                            new StringLiteral { "2000-12-31" },
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
                //         StringLiteral { "2001-01-01" }.greater_equal("2000-12-31"s),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p"
                " WHERE '2001-01-01' >= '2000-12-31'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c WhereClause @n
     * @li @c condition_expression : @c BinaryOperation ( 下記参照 )
     *
     * @c BinaryOperation @n
     * @li @c operater : ≪IS演算≫ ( @c is )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::with_where_clause_and_is()
        -> std::vector<SelectStatementDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _103
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪IS演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Is,
                            new IdentifierExpression { "p.nickname" },
                            new IdentifierExpression { "p.nickname" },
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
                //         IdentifierExpression { "p.nickname" }
                //         .is(IdentifierExpression { "p.nickname" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.nickname IS p.nickname",
            },

            // _104
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪IS演算≫
            //         + left     : ≪識別子式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Is,
                            new IdentifierExpression { "p.nickname" },
                            new NullLiteral { },
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
                //         IdentifierExpression { "p.nickname" }.is(sqlxx::null),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.nickname IS NULL",
            },

            // _105
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪IS演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪識別子式≫
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
                            OperationKind::Is,
                            new NullLiteral { },
                            new IdentifierExpression { "p.nickname" },
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
                //         sqlxx::null.is(IdentifierExpression { "p.nickname" }),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE NULL IS p.nickname",
            },

            // _106
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : ≪IS演算≫
            //         + left     : ≪リテラル式≫
            //         + right    : ≪リテラル式≫
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
                            OperationKind::Is,
                            new NullLiteral { },
                            new NullLiteral { },
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
                //         sqlxx::null.is(sqlxx::null),
                //     },
                // },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE NULL IS NULL",
            },
        };
        // clang-format on
    }
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_01_HXX */
