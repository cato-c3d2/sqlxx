/*!
 * @file select-statement-data-set.class-member.05-with-where-clause.00.h++
 */

#ifndef TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_00_HXX
#define TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_00_HXX

#include <vector>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/clause/select-clause.class.h++>
#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
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
     * ----------------------------------------
     * |     | WhereClause                    |
     * |     |--------------------------------|
     * |     | condition_expression           |
     * |=====|================================|
     * | _69 | -                              |
     * ----------------------------------------
     *
     * ----------------------------------------
     * |     | WhereClause                    |
     * |     |--------------------------------|
     * |     | condition_expression           |
     * |     |--------------------------------|
     * |     | BinaryOperation                |
     * |     |--------------------------------|
     * |     | operater | left     | right    |
     * |=====|==========|==========|==========|
     * | _70 | -        | -        | -        |
     * |-----|----------|----------|----------|
     * | _71 | o        | o        | o        |
     * |-----|          |          |----------|
     * | _72 |          |          | -        |
     * |-----|          |----------|----------|
     * | ___ |          | -        | o        | ※コンパイル不可
     * |-----|          |          |----------|
     * | _73 |          |          | -        |
     * |-----|----------|----------|----------|
     * | _74 | x        | o        | o        |
     * |-----|          |          |----------|
     * | ___ |          |          | -        | ※コンパイル不可
     * |-----|          |----------|----------|
     * | _75 |          | -        | o        |
     * |-----|          |          |----------|
     * | _76 |          |          | -        |
     * ----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - ... 未指定
     * @li o ... 有効値
     * @li x ... 無効値 (
     *           @c operater : @c BinaryOperationKind::None )
     *
     * [ 構成 ] @n
     * @li       _69 : @link with_where_clause_of_built_by_default_construction()   @endlink
     * @li _70 ~ _76 : @link with_where_clause_of_built_by_undefault_construction() @endlink
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
     *
     * @see sqlxx::clause::WhereClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::WhereClause::to_string() テスト対象メンバ関数
     */
    auto
    SelectStatementDataSet::with_where_clause_of_built_by_any_construction()
        -> std::vector<SelectStatementDataSetElement>
    {
        std::vector<std::vector<SelectStatementDataSetElement>>
            data_set_parts = {
                // clang-format off
                SelectStatementDataSet::with_where_clause_of_built_by_default_construction(),
                SelectStatementDataSet::with_where_clause_of_built_by_undefault_construction(),
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
     * @c WhereClause : デフォルトコンストラクタにより構築したオブジェクト
     * ( @c SelectClause 及び @c FromClause は下記を参照のこと)
     *
     * @c SelectClause : 下記参照
     *
     * @c columns[0] : @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @c columns[1] : @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @c FromClause : 下記参照
     *
     * @c table : @n
     * @li @c name      : 指定
     * @li @c as_clause : 指定
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto
    SelectStatementDataSet::with_where_clause_of_built_by_default_construction()
        -> std::vector<SelectStatementDataSetElement>
    {
        // clang-format off
        return {
            // _69
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause : デフォルトコンストラクタにより構築したオブジェクト
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
                    WhereClause {},
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
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
     * @li @c operater : 有効値 or 無効値( @c BinaryOperationKind::None )
     * @li @c left     : 有効値 or 無効値( @c nullptr )
     * @li @c right    : 有効値 or 無効値( @c nullptr )
     *
     * @return ≪SELECT文≫のテストケースで使用するデータセット
     */
    auto SelectStatementDataSet::
        with_where_clause_of_built_by_undefault_construction()
            -> std::vector<SelectStatementDataSetElement>
    {
        // clang-format off
        return {
            // _70
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 未指定
            //         + left     : 未指定
            //         + right    : 未指定
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
                        BinaryOperation {},
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },

            // _71
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 有効値
            //         + left     : 有効値
            //         + right    : 有効値
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
                            BinaryOperationKind::EqualTo,
                            IdentifierExpression { "p.id" },
                            IntegerLiteral { 1234 },
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p WHERE p.id = 1234",
            },

            // _72
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 有効値
            //         + left     : 有効値
            //         + right    : 未指定
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
                            BinaryOperationKind::EqualTo,
                            IdentifierExpression { "p.id" },
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },

            // _73
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 有効値
            //         + left     : 未指定
            //         + right    : 未指定
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
                            BinaryOperationKind::EqualTo,
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },

            // _74
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 無効値
            //         + left     : 有効値
            //         + right    : 有効値
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
                            BinaryOperationKind::None,
                            IdentifierExpression { "p.id" },
                            IntegerLiteral { 1234 },
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },

            // _75
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 無効値
            //         + left     : 有効値
            //         + right    : 未指定
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
                            BinaryOperationKind::None,
                            IdentifierExpression { "p.id" },
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },

            // _76
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + WhereClause
            //     + BinaryOperation
            //         + operater : 無効値
            //         + left     : 未指定
            //         + right    : 未指定
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
                            BinaryOperationKind::None,
                        },
                    },
                },

                // 期待結果 - to_string メンバ関数
                "SELECT id AS p.id, name AS p.name FROM people AS p",
            },
        };
        // clang-format on
    }
} // namespace statement
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__STATEMENT__DATA_SET__DEFINITION__SELECT_STATEMENT_DATA_SET_CLASS_MEMBER_05_WITH_WHERE_CLAUSE_00_HXX */
