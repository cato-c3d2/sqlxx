/*!
 * @file condition-expression-data-set.class-member.01.pattern_by_comparison_operation.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX

#include <iterator>
#include <vector>

#include <sql++/expression/condition-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/null-literal.class.h++>
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
     * |  _9 | =        | IE       | IE       |
     * |-----|          |          |----------|
     * | _10 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _11 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _12 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _13 | <>       | IE       | IE       |
     * |-----|          |          |----------|
     * | _14 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _15 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _16 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _17 | <        | IE       | IE       |
     * |-----|          |          |----------|
     * | _18 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _19 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _20 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _21 | <=       | IE       | IE       |
     * |-----|          |          |----------|
     * | _22 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _23 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _24 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _25 | >        | IE       | IE       |
     * |-----|          |          |----------|
     * | _26 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _27 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _28 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _29 | >=       | IE       | IE       |
     * |-----|          |          |----------|
     * | _30 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _31 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _32 |          |          | LE       |
     * |-----|----------|----------|----------|
     * | _33 | IS       | IE       | IE       |
     * |-----|          |          |----------|
     * | _34 |          |          | LE       |
     * |-----|          |----------|----------|
     * | _35 |          | LE       | IE       |
     * |-----|          |          |----------|
     * | _36 |          |          | LE       |
     * ----------------------------------------
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
     * @li  _9 ~ _12 : @link pattern_by_equal_to()      @endlink
     * @li _13 ~ _16 : @link pattern_by_not_equal_to()  @endlink
     * @li _17 ~ _20 : @link pattern_by_less()          @endlink
     * @li _21 ~ _24 : @link pattern_by_less_equal()    @endlink
     * @li _25 ~ _28 : @link pattern_by_greater()       @endlink
     * @li _29 ~ _32 : @link pattern_by_greater_equal() @endlink
     * @li _33 ~ _36 : @link pattern_by_is()            @endlink
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_comparison_operation()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        std::vector<std::vector<ConditionExpressionDataSetElement>>
            data_set_parts = {
                // clang-format off
                ConditionExpressionDataSet::pattern_by_equal_to(),
                ConditionExpressionDataSet::pattern_by_not_equal_to(),
                ConditionExpressionDataSet::pattern_by_less(),
                ConditionExpressionDataSet::pattern_by_less_equal(),
                ConditionExpressionDataSet::pattern_by_greater(),
                ConditionExpressionDataSet::pattern_by_greater_equal(),
                ConditionExpressionDataSet::pattern_by_is(),
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
     * @li @c operater : ≪等値比較演算≫ ( @c equal_to )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_equal_to()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _9
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪等値比較演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new IdentifierExpression { "p.name" },
                    new IdentifierExpression { "p.nickname" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }
                .equal_to(IdentifierExpression { "p.nickname" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name = p.nickname",
            },

            // _10
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪等値比較演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new IdentifierExpression { "p.name" },
                    new StringLiteral { "John Doe" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }.equal_to("John Doe"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name = 'John Doe'",
            },

            // _11
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪等値比較演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new StringLiteral { "John Doe" },
                    new IdentifierExpression { "p.name" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "John Doe" }.equal_to(IdentifierExpression { "p.name" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'John Doe' = p.name",
            },

            // _12
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪等値比較演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::EqualTo,
                    new StringLiteral { "john doe" },
                    new StringLiteral { "JOHN DOE" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "john doe" }.equal_to("JOHN DOE"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'john doe' = 'JOHN DOE'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪非等値比較演算≫ ( @c not_equal_to )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_not_equal_to()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _13
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪非等値比較演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::NotEqualTo,
                    new IdentifierExpression { "p.name" },
                    new IdentifierExpression { "p.nickname" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }
                .not_equal_to(IdentifierExpression { "p.nickname" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name <> p.nickname",
            },

            // _14
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪非等値比較演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::NotEqualTo,
                    new IdentifierExpression { "p.name" },
                    new StringLiteral { "John Doe" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.name" }.not_equal_to("John Doe"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.name <> 'John Doe'",
            },

            // _15
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪非等値比較演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::NotEqualTo,
                    new StringLiteral { "John Doe" },
                    new IdentifierExpression { "p.name" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "John Doe" }.not_equal_to(IdentifierExpression { "p.name" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'John Doe' <> p.name",
            },

            // _16
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪非等値比較演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::NotEqualTo,
                    new StringLiteral { "john doe" },
                    new StringLiteral { "JOHN DOE" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "john doe" }.not_equal_to("JOHN DOE"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'john doe' <> 'JOHN DOE'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪比較演算（小なり）≫ ( @c less )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_less()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _17
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（小なり）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Less,
                    new IdentifierExpression { "p.created_at" },
                    new IdentifierExpression { "p.updated_at" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }
                .less(IdentifierExpression { "p.updated_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at < p.updated_at",
            },

            // _18
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（小なり）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Less,
                    new IdentifierExpression { "p.created_at" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }.less("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at < '2001-01-01'",
            },

            // _19
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（小なり）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Less,
                    new StringLiteral { "2001-01-01" },
                    new IdentifierExpression { "p.created_at" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }.less(IdentifierExpression { "p.created_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' < p.created_at",
            },

            // _20
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（小なり）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Less,
                    new StringLiteral { "2000-12-31" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2000-12-31" }.less("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2000-12-31' < '2001-01-01'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪比較演算（以下）≫ ( @c less_equal )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_less_equal()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _21
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以下）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LessEqual,
                    new IdentifierExpression { "p.created_at" },
                    new IdentifierExpression { "p.updated_at" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }
                .less_equal(IdentifierExpression { "p.updated_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at <= p.updated_at",
            },

            // _22
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以下）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LessEqual,
                    new IdentifierExpression { "p.created_at" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }.less_equal("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at <= '2001-01-01'",
            },

            // _23
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以下）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LessEqual,
                    new StringLiteral { "2001-01-01" },
                    new IdentifierExpression { "p.created_at" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }.less_equal(IdentifierExpression { "p.created_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' <= p.created_at",
            },

            // _24
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以下）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::LessEqual,
                    new StringLiteral { "2000-12-31" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2000-12-31" }.less_equal("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2000-12-31' <= '2001-01-01'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪比較演算（大なり）≫ ( @c greater )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_greater()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _25
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（大なり）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Greater,
                    new IdentifierExpression { "p.created_at" },
                    new IdentifierExpression { "p.updated_at" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }
                .greater(IdentifierExpression { "p.updated_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at > p.updated_at",
            },

            // _26
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（大なり）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Greater,
                    new IdentifierExpression { "p.created_at" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }.greater("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at > '2001-01-01'",
            },

            // _27
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（大なり）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Greater,
                    new StringLiteral { "2001-01-01" },
                    new IdentifierExpression { "p.created_at" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }.greater(IdentifierExpression { "p.created_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' > p.created_at",
            },

            // _28
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（大なり）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Greater,
                    new StringLiteral { "2001-01-01" },
                    new StringLiteral { "2000-12-31" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }.greater("2000-12-31"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' > '2000-12-31'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪比較演算（以上）≫ ( @c greater_equal )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_greater_equal()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _29
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以上）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::GreaterEqual,
                    new IdentifierExpression { "p.created_at" },
                    new IdentifierExpression { "p.updated_at" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }
                .greater_equal(IdentifierExpression { "p.updated_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at >= p.updated_at",
            },

            // _30
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以上）≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::GreaterEqual,
                    new IdentifierExpression { "p.created_at" },
                    new StringLiteral { "2001-01-01" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.created_at" }.greater_equal("2001-01-01"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.created_at >= '2001-01-01'",
            },

            // _31
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以上）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::GreaterEqual,
                    new StringLiteral { "2001-01-01" },
                    new IdentifierExpression { "p.created_at" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }
                .greater_equal(IdentifierExpression { "p.created_at" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' >= p.created_at",
            },

            // _32
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪比較演算（以上）≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::GreaterEqual,
                    new StringLiteral { "2001-01-01" },
                    new StringLiteral { "2000-12-31" },
                },

                // テスト対象オブジェクト - DSL記法
                StringLiteral { "2001-01-01" }.greater_equal("2000-12-31"s),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "'2001-01-01' >= '2000-12-31'",
            },
        };
        // clang-format on
    }

    /*!
     * [ データパターン ] @n
     * @c ConditionExpression @n
     * @li @c operater : ≪IS演算≫ ( @c is )
     * @li @c left     : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     * @li @c right    : ≪識別子式≫ ( @c IdentifierExpression ) or
     *                   ≪リテラル式≫ ( @c BasicLiteral )
     *
     * @return ≪条件式≫のテストケースで使用するデータセット
     */
    auto ConditionExpressionDataSet::pattern_by_is()
        -> std::vector<ConditionExpressionDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _33
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪IS演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Is,
                    new IdentifierExpression { "p.nickname" },
                    new IdentifierExpression { "p.nickname" },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.nickname" }.is(IdentifierExpression { "p.nickname" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.nickname IS p.nickname",
            },

            // _34
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪IS演算≫
            //     + left     : ≪識別子式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Is,
                    new IdentifierExpression { "p.nickname" },
                    new NullLiteral { },
                },

                // テスト対象オブジェクト - DSL記法
                IdentifierExpression { "p.nickname" }.is(sqlxx::null),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "p.nickname IS NULL",
            },

            // _35
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪IS演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪識別子式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Is,
                    new NullLiteral { },
                    new IdentifierExpression { "p.nickname" },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::null.is(IdentifierExpression { "p.nickname" }),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NULL IS p.nickname",
            },

            // _36
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + ConditionExpression
            //     + operater : ≪IS演算≫
            //     + left     : ≪リテラル式≫
            //     + right    : ≪リテラル式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                ConditionExpression {
                    OperationKind::Is,
                    new NullLiteral { },
                    new NullLiteral { },
                },

                // テスト対象オブジェクト - DSL記法
                sqlxx::null.is(sqlxx::null),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NULL IS NULL",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__CONDITION_EXPRESSION_DATA_SET_CLASS_MEMBER_01_PATTERN_BY_COMPARISON_OPERATION_HXX */
