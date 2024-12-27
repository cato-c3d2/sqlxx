/*!
 * @file unary-operation-data-set.class-member.02.pattern_by_logical_operation.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX

#include <iterator>
#include <vector>

#include <sql++/expression/grouped-expression.class.h++>
#include <sql++/expression/identifier-expression.class.h++>
#include <sql++/expression/literal/string-literal.class.h++>
#include <sql++/expression/operation/binary-operation.class.h++>
#include <sql++/expression/operation/operation-kind.enum-class.h++>
#include <sql++/expression/operation/unary-operation-kind.enum-class.h++>
#include <sql++/expression/operation/unary-operation.class.h++>

#include "../unary-operation-data-set-element.class.h++"

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
     * ----------------------------
     * |    | UnaryOperation      |
     * |    |---------------------|
     * |    | operater | operand  |
     * |====|==========|==========|
     * | _5 | NOT      | CE       |
     * |----|          |----------|
     * | _6 |          | GE       |
     * ----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li NOT ... ≪論理否定演算式≫ ( @c logical_not )
     * @li CE  ... ≪条件式≫ ( @c ConditionExpression )
     * @li GE  ... ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * [ 構成 ] @n
     * @li _5 ~ _6 : @link pattern_by_logical_not() @endlink
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto UnaryOperationDataSet::pattern_by_logical_operation()
        -> std::vector<UnaryOperationDataSetElement>
    {
        std::vector<std::vector<UnaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                UnaryOperationDataSet::pattern_by_logical_not(),
                // clang-format on
            };

        auto data_set = std::vector<UnaryOperationDataSetElement>();
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
     * @c UnaryOperation @n
     * @li @c operater : ≪論理否定演算式≫ ( @c logical_not )
     * @li @c operand  : ≪条件式≫ ( @c ConditionExpression ) or
     *                   ≪グループ化された式≫ ( @c GroupedExpression )
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto UnaryOperationDataSet::pattern_by_logical_not()
        -> std::vector<UnaryOperationDataSetElement>
    {
        using namespace std::literals::string_literals;

        // clang-format off
        return {
            // _5
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operater : ≪論理否定演算式≫
            //     + operand  : ≪条件式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::LogicalNot,
                    new BinaryOperation {
                        BinaryOperationKind::GreaterEqual,
                        new IdentifierExpression { "p.birth_day" },
                        new StringLiteral { "1901-01-01" },
                    },
                },

                // テスト対象オブジェクト - DSL記法
                logical_not(
                    IdentifierExpression { "p.birth_day" }.greater_equal("1901-01-01"s)
                ),

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT p.birth_day >= '1901-01-01'"
            },

            // _6
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operater : ≪論理否定演算式≫
            //     + operand  : ≪グループ化された式≫
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::LogicalNot,
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
                logical_not(
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
                "NOT (p.birth_day >= '1901-01-01' AND p.birth_day <= '2000-12-31')",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_02_PATTERN_BY_LOGICAL_OPERATION_HXX */
