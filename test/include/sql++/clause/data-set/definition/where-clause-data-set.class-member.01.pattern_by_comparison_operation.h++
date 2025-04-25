/*!
 * @file where-clause-data-set.class-member.01.pattern_by_comparison_operation.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX

#include <iterator>
#include <vector>

#include <sql++/clause/where-clause.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/null-literal.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>

#include "../where-clause-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace clause
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
     * |     |--------------------------------|
     * |     | BinaryOperation                |
     * |     |--------------------------------|
     * |     | operater | left     | right    |
     * |=====|==========|==========|==========|
     * |  _8 | =        | IE       | IE       |
     * |-----|          |          |----------|
     * |  _9 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _10 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _11 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _12 | <>       | IE       | IE       |
     * |-----|          |          |----------|
     * | _13 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _14 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _15 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _16 | <        | IE       | IE       |
     * |-----|          |          |----------|
     * | _17 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _18 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _19 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _20 | <=       | IE       | IE       |
     * |-----|          |          |----------|
     * | _21 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _22 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _23 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _24 | >        | IE       | IE       |
     * |-----|          |          |----------|
     * | _25 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _26 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _27 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _28 | >=       | IE       | IE       |
     * |-----|          |          |----------|
     * | _29 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _30 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _31 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _32 | IS       | IE       | IE       |
     * |-----|          |          |----------|
     * | _33 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _34 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _35 |          |          | LE       |
     * ----------------------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li =  : ≪等値比較演算≫（ @c equal_to ）
     * @li <> : ≪非等値比較演算≫（ @c not_equal_to ）
     * @li <  : ≪比較演算（小なり）≫（ @c less ）
     * @li <= : ≪比較演算（以下）≫（ @c less_equal ）
     * @li >  : ≪比較演算（大なり）≫（ @c greater ）
     * @li >= : ≪比較演算（以上）≫（ @c greater_equal ）
     * @li IS : ≪IS演算≫（ @c is ）
     * @li IE : ≪識別子式≫（ @c IdentifierExpression ）
     * @li LE : ≪リテラル式≫（ @c BasicLiteral ）
     *
     * [ 構成 ] @n
     * @li  _8 ~ _11 : @link pattern_by_equal_to()      @endlink
     * @li _12 ~ _15 : @link pattern_by_not_equal_to()  @endlink
     * @li _16 ~ _19 : @link pattern_by_less()          @endlink
     * @li _20 ~ _23 : @link pattern_by_less_equal()    @endlink
     * @li _24 ~ _27 : @link pattern_by_greater()       @endlink
     * @li _28 ~ _31 : @link pattern_by_greater_equal() @endlink
     * @li _32 ~ _35 : @link pattern_by_is()            @endlink
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_comparison_operation()
        -> std::vector<WhereClauseDataSetElement>
    {
        std::vector<std::vector<WhereClauseDataSetElement>> data_set_parts = {
            // clang-format off
            WhereClauseDataSet::pattern_by_equal_to(),
            WhereClauseDataSet::pattern_by_not_equal_to(),
            WhereClauseDataSet::pattern_by_less(),
            WhereClauseDataSet::pattern_by_less_equal(),
            WhereClauseDataSet::pattern_by_greater(),
            WhereClauseDataSet::pattern_by_greater_equal(),
            WhereClauseDataSet::pattern_by_is(),
            // clang-format on
        };

        auto data_set = std::vector<WhereClauseDataSetElement>();
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
     * @li @c operater : ≪等値比較演算≫（ @c equal_to ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_equal_to()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _8
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        IdentifierExpression { "p.name" },
                        IdentifierExpression { "p.nickname" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.name" }
                    .equal_to(IdentifierExpression { "p.nickname" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.name = p.nickname",
            },

            // _9
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        IdentifierExpression { "p.name" },
                        StringLiteral { "John Doe" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.name" }.equal_to("John Doe"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.name = 'John Doe'",
            },

            // _10
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        StringLiteral { "John Doe" },
                        IdentifierExpression { "p.name" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "John Doe" }.equal_to(IdentifierExpression { "p.name" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE 'John Doe' = p.name",
            },

            // _11
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::EqualTo,
                        StringLiteral { "john doe" },
                        StringLiteral { "JOHN DOE" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "john doe" }.equal_to("JOHN DOE"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE 'john doe' = 'JOHN DOE'",
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
     * @li @c operater : ≪非等値比較演算≫（ @c not_equal_to ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_not_equal_to()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _12
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::NotEqualTo,
                        IdentifierExpression { "p.name" },
                        IdentifierExpression { "p.nickname" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.name" }
                    .not_equal_to(IdentifierExpression { "p.nickname" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.name <> p.nickname",
            },

            // _13
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::NotEqualTo,
                        IdentifierExpression { "p.name" },
                        StringLiteral { "John Doe" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.name" }.not_equal_to("John Doe"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.name <> 'John Doe'",
            },

            // _14
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::NotEqualTo,
                        StringLiteral { "John Doe" },
                        IdentifierExpression { "p.name" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "John Doe" }.not_equal_to(IdentifierExpression { "p.name" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE 'John Doe' <> p.name",
            },

            // _15
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::NotEqualTo,
                        StringLiteral { "john doe" },
                        StringLiteral { "JOHN DOE" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "john doe" }.not_equal_to("JOHN DOE"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE 'john doe' <> 'JOHN DOE'",
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
     * @li @c operater : ≪比較演算（小なり）≫（ @c less ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_less()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _16
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Less,
                        IdentifierExpression { "p.created_at" },
                        IdentifierExpression { "p.updated_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }
                    .less(IdentifierExpression { "p.updated_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at < p.updated_at",
            },

            // _17
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Less,
                        IdentifierExpression { "p.created_at" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }.less("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at < '2001-01-01'",
            },

            // _18
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Less,
                        StringLiteral { "2001-01-01" },
                        IdentifierExpression { "p.created_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }.less(IdentifierExpression { "p.created_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' < p.created_at",
            },

            // _19
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Less,
                        StringLiteral { "2000-12-31" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2000-12-31" }.less("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2000-12-31' < '2001-01-01'",
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
     * @li @c operater : ≪比較演算（以下）≫（ @c less_equal ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_less_equal()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _20
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::LessEqual,
                        IdentifierExpression { "p.created_at" },
                        IdentifierExpression { "p.updated_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }
                    .less_equal(IdentifierExpression { "p.updated_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at <= p.updated_at",
            },

            // _21
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::LessEqual,
                        IdentifierExpression { "p.created_at" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }.less_equal("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at <= '2001-01-01'",
            },

            // _22
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::LessEqual,
                        StringLiteral { "2001-01-01" },
                        IdentifierExpression { "p.created_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }
                    .less_equal(IdentifierExpression { "p.created_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' <= p.created_at",
            },

            // _23
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::LessEqual,
                        StringLiteral { "2000-12-31" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2000-12-31" }.less_equal("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2000-12-31' <= '2001-01-01'",
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
     * @li @c operater : ≪比較演算（大なり）≫（ @c greater ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_greater()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _24
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Greater,
                        IdentifierExpression { "p.created_at" },
                        IdentifierExpression { "p.updated_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }
                    .greater(IdentifierExpression { "p.updated_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at > p.updated_at",
            },

            // _25
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Greater,
                        IdentifierExpression { "p.created_at" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }.greater("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at > '2001-01-01'",
            },

            // _26
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Greater,
                        StringLiteral { "2001-01-01" },
                        IdentifierExpression { "p.created_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }.greater(IdentifierExpression { "p.created_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' > p.created_at",
            },

            // _27
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Greater,
                        StringLiteral { "2001-01-01" },
                        StringLiteral { "2000-12-31" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }.greater("2000-12-31"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' > '2000-12-31'",
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
     * @li @c operater : ≪比較演算（以上）≫（ @c greater_equal ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_greater_equal()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _28
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        IdentifierExpression { "p.created_at" },
                        IdentifierExpression { "p.updated_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }
                    .greater_equal(IdentifierExpression { "p.updated_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at >= p.updated_at",
            },

            // _29
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        IdentifierExpression { "p.created_at" },
                        StringLiteral { "2001-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.created_at" }.greater_equal("2001-01-01"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.created_at >= '2001-01-01'",
            },

            // _30
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        StringLiteral { "2001-01-01" },
                        IdentifierExpression { "p.created_at" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }
                    .greater_equal(IdentifierExpression { "p.created_at" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' >= p.created_at",
            },

            // _31
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        StringLiteral { "2001-01-01" },
                        StringLiteral { "2000-12-31" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    StringLiteral { "2001-01-01" }.greater_equal("2000-12-31"s),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE '2001-01-01' >= '2000-12-31'",
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
     * @li @c operater : ≪IS演算≫（ @c is ）
     * @li @c left     : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     * @li @c right    : ≪識別子式≫（ @c IdentifierExpression ） or
     *                   ≪リテラル式≫（ @c BasicLiteral ）
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     */
    auto WhereClauseDataSet::pattern_by_is()
        -> std::vector<WhereClauseDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _32
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Is,
                        IdentifierExpression { "p.nickname" },
                        IdentifierExpression { "p.nickname" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.nickname" }.is(IdentifierExpression { "p.nickname" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.nickname IS p.nickname",
            },

            // _33
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Is,
                        IdentifierExpression { "p.nickname" },
                        NullLiteral { },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    IdentifierExpression { "p.nickname" }.is(sqlxx::null),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE p.nickname IS NULL",
            },

            // _34
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Is,
                        NullLiteral { },
                        IdentifierExpression { "p.nickname" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    sqlxx::null.is(IdentifierExpression { "p.nickname" }),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE NULL IS p.nickname",
            },

            // _35
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
                WhereClause {
                    BinaryOperation {
                        BinaryOperationKind::Is,
                        NullLiteral { },
                        NullLiteral { },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                WhereClause {
                    sqlxx::null.is(sqlxx::null),
                },

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "WHERE NULL IS NULL",
            },
        };
        // clang-format on
    }
} // namespace clause
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX */
