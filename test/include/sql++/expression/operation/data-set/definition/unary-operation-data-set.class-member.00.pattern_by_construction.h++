/*!
 * @file unary-operation-data-set.class-member.00.pattern_by_construction.h++
 */

#ifndef TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX
#define TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX

#include <iterator>
#include <optional>
#include <vector>

#include <sql++/expression/literal/null-literal.class.h++>
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
     * |    | operator | operand  |
     * |====|==========|==========|
     * | _0 | -        | -        |
     * |----|----------|----------|
     * | _1 | o        | o        |
     * |----|          |----------|
     * | _2 |          | -        |
     * |----|----------|----------|
     * | _3 | x        | o        |
     * |----|          |----------|
     * | _4 |          | -        |
     * ----------------------------
     * </pre>
     *
     * [ 凡例 ] @n
     * @li - : 未指定
     * @li o : 有効値
     * @li x : 無効値（ @c operator : @c UnaryOperationKind::None ）
     *
     * [ 構成 ] @n
     * @li      _0 : @link pattern_by_default_construction()   @endlink
     * @li _1 ~ _4 : @link pattern_by_undefault_construction() @endlink
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto UnaryOperationDataSet::pattern_by_construction()
        -> std::vector<UnaryOperationDataSetElement>
    {
        std::vector<std::vector<UnaryOperationDataSetElement>>
            data_set_parts = {
                // clang-format off
                UnaryOperationDataSet::pattern_by_default_construction(),
                UnaryOperationDataSet::pattern_by_undefault_construction(),
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
     * @c UnaryOperation : デフォルトコンストラクタにより構築したオブジェクト
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto UnaryOperationDataSet::pattern_by_default_construction()
        -> std::vector<UnaryOperationDataSetElement>
    {
        // clang-format off
        return {
            // _0
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation : デフォルトコンストラクタにより構築したオブジェクト
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {},

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

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
     * @c UnaryOperation @n
     * @li @c operator : 有効値 or 無効値（ @c UnaryOperationKind::None ）
     * @li @c operand  : 有効値 or 無効値（ @c nullptr ）
     *
     * @return ≪二項演算式≫のテストケースで使用するデータセット
     */
    auto UnaryOperationDataSet::pattern_by_undefault_construction()
        -> std::vector<UnaryOperationDataSetElement>
    {
        // clang-format off
        return {
            // _1
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operator : 有効値
            //     + operand  : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::LogicalNot,
                    NullLiteral {},
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                false,

                // 期待結果 - to_string メンバ関数
                "NOT NULL",
            },

            // _2
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operator : 有効値
            //     + operand  : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::LogicalNot,
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _3
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operator : 無効値
            //     + operand  : 有効値
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::None,
                    NullLiteral {},
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },

            // _4
            ////////////////////////////////////////////////////////////////////
            // [ データパターン ]
            // + UnaryOperation
            //     + operator : 無効値
            //     + operand  : 未指定
            ////////////////////////////////////////////////////////////////////
            {
                // テスト対象オブジェクト - 非DSL記法
                UnaryOperation {
                    UnaryOperationKind::None,
                },

                // テスト対象オブジェクト - DSL記法
                std::nullopt,

                // 期待結果 - empty メンバ関数
                true,

                // 期待結果 - to_string メンバ関数
                "",
            },
        };
        // clang-format on
    }
} // namespace expression
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__EXPRESSION__DATA_SET__OPERATION__UNARY_OPERATION_DATA_SET_CLASS_MEMBER_00_PATTERN_BY_CONSTRUCTION_HXX */
