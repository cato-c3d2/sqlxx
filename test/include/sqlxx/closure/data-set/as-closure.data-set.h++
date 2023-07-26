/*!
 * @file as-closure.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX

#include <vector>

#include <sql++/closure/as-closure.class.h++>

#include "./as-closure-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace
{
    using sqlxx::closure::AsClosure;

    /*!
     * @brief @c AsClosure クラスのテストケースで使用するデータセット
     */
    class AsClosureDataSet
    {
    public:
        static auto for_some_test_case()
            -> std::vector<AsClosureDataSetElement>;
    };

    /*!
     * @brief  データセットを返却する
     *
     * [ データパターン表 ] @n
     * <pre>
     * ---------------------
     * |     | alias_name  |
     * =====================
     * |  _0 |      -      |
     * |  _1 |      e      |
     * |  _2 |      x      |
     * |  _3 |      o      |
     * ---------------------
     * </pre>
     *
     * [[ 凡例 ]] @n
     * @li o ... 指定(適格)
     * @li e ... 指定(不適格(空文字列))
     * @li x ... 指定(不適格(半角スペース))
     * @li - ... 未指定
     *
     * @return データセット
     *
     * @see sqlxx::closure::AsClosure              テスト対象クラス
     * @see sqlxx::closure::AsClosure::empty()     テスト対象メンバ関数
     * @see sqlxx::closure::AsClosure::to_string() テスト対象メンバ関数
     */
    auto AsClosureDataSet::for_some_test_case()
        -> std::vector<AsClosureDataSetElement>
    {
        // clang-format off
        return {
            // _0
            {
                // [条件]
                // + alias_name : 未指定
                AsClosure {},
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _1
            {
                // [条件]
                // + alias_name : 空文字列
                AsClosure { "" },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _2
            {
                // [条件]
                // + alias_name : 不適格(半角スペース)
                AsClosure { " " },
                // [期待結果] empty メンバ関数
                true,
                // [期待結果] to_string メンバ関数
                ""
            },
            // _3
            {
                // [条件]
                // + alias_name : 適格(カラム指定)
                AsClosure { "p.id" },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "AS p.id"
            },
            // _4
            {
                // [条件]
                // + alias_name : 適格(テーブル指定)
                AsClosure { "p" },
                // [期待結果] empty メンバ関数
                false,
                // [期待結果] to_string メンバ関数
                "AS p"
            }
        };
        // clang-format on
    }
} // namespace
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_HXX */
