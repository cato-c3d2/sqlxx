/*!
 * @file where-clause-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_HXX

#include <iterator>
#include <optional>
#include <vector>

#include "./where-clause-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace clause
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ≪WHERE句≫のテストケースで使用するデータセット
     *
     * @see sqlxx::clause::WhereClause              テスト対象クラス
     * @see sqlxx::test::clause::WhereClauseDataSet データセット要素
     */
    class WhereClauseDataSet
    {
    public:
        /*! @brief ≪WHERE句≫のテストケースで使用するデータセットを生成する */
        static auto for_some_test_case()
            -> std::vector<WhereClauseDataSetElement>;

    protected:
        /*! @brief データパターン : 任意の引数によりオブジェクトを構築する */
        static auto pattern_by_construction()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪比較演算≫を指定する */
        static auto pattern_by_comparison_operation()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪論理演算≫を指定する */
        static auto pattern_by_logical_operation()
            -> std::vector<WhereClauseDataSetElement>;

    private:
        /*! @brief データパターン : デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_default_construction()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : 非デフォルトコンストラクタによりオブジェクトを構築する */
        static auto pattern_by_undefault_construction()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪等値比較演算≫を指定する */
        static auto pattern_by_equal_to()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪非等値比較演算≫を指定する */
        static auto pattern_by_not_equal_to()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪比較演算（小なり）≫を指定する */
        static auto pattern_by_less() -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪比較演算（以下）≫を指定する */
        static auto pattern_by_less_equal()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪比較演算（大なり）≫を指定する */
        static auto pattern_by_greater()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪比較演算（以上）≫を指定する */
        static auto pattern_by_greater_equal()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪IS演算≫を指定する */
        static auto pattern_by_is() -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪論理積演算≫を指定する */
        static auto pattern_by_logical_and()
            -> std::vector<WhereClauseDataSetElement>;

        /*! @brief データパターン : ≪論理和演算≫を指定する */
        static auto pattern_by_logical_or()
            -> std::vector<WhereClauseDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * [ データパターンと構成 ] @n
     * @li @link pattern_by_construction()         @endlink : 任意の引数によりオブジェクトを構築する
     * @li @link pattern_by_comparison_operation() @endlink : ≪比較演算≫を指定する
     * @li @link pattern_by_logical_operation()    @endlink : ≪論理演算≫を指定する
     *
     * @return ≪WHERE句≫のテストケースで使用するデータセット
     *
     * @see sqlxx::clause::WhereClause::empty()     テスト対象メンバ関数
     * @see sqlxx::clause::WhereClause::to_string() テスト対象メンバ関数
     */
    auto WhereClauseDataSet::for_some_test_case()
        -> std::vector<WhereClauseDataSetElement>
    {
        std::vector<std::vector<WhereClauseDataSetElement>> data_set_parts = {
            // clang-format off
            WhereClauseDataSet::pattern_by_construction(),
            WhereClauseDataSet::pattern_by_comparison_operation(),
            WhereClauseDataSet::pattern_by_logical_operation(),
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
} // namespace clause
} // namespace sqlxx::test

#include "./definition/where-clause-data-set.class-member.00.pattern_by_construction.h++"
#include "./definition/where-clause-data-set.class-member.01.pattern_by_comparison_operation.h++"
#include "./definition/where-clause-data-set.class-member.02.pattern_by_logical_operation.h++"

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__DATA_SET__WHERE_CLAUSE_DATA_SET_HXX */
