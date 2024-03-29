/*!
 * @file naming-rule-data-set.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./naming-rule-data-set-element.class.h++"

namespace sqlxx::test
{
inline namespace identifier
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief @c NamingRule クラスのテストケースで使用するデータセット
     */
    class NamingRuleDataSet
    {
    public:
        /*!
        * @brief  データセットを返却する
        *
        * @return データセット
        *
        * @see sqlxx::identifier::NamingRule             テスト対象クラス
        * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
        */
        static auto for_is_legal() -> std::vector<NamingRuleDataSetElement>;

    private:
        static auto for_is_legal_() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_00() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01A() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01a() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01d() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01s() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01x() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_01z() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02A() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02a() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02c() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02d() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02e() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02f() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02g() -> std::vector<NamingRuleDataSetElement>;
        static auto for_is_legal_02h() -> std::vector<NamingRuleDataSetElement>;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto NamingRuleDataSet::for_is_legal()
        -> std::vector<NamingRuleDataSetElement>
    {
        std::vector<std::vector<NamingRuleDataSetElement>> data_set_parts = {
            NamingRuleDataSet::for_is_legal_(),
            NamingRuleDataSet::for_is_legal_00(),
            NamingRuleDataSet::for_is_legal_01A(),
            NamingRuleDataSet::for_is_legal_01a(),
            NamingRuleDataSet::for_is_legal_01d(),
            NamingRuleDataSet::for_is_legal_01s(),
            NamingRuleDataSet::for_is_legal_01x(),
            NamingRuleDataSet::for_is_legal_01z(),
            NamingRuleDataSet::for_is_legal_02A(),
            NamingRuleDataSet::for_is_legal_02a(),
            NamingRuleDataSet::for_is_legal_02c(),
            NamingRuleDataSet::for_is_legal_02d(),
            NamingRuleDataSet::for_is_legal_02e(),
            NamingRuleDataSet::for_is_legal_02f(),
            NamingRuleDataSet::for_is_legal_02g(),
            NamingRuleDataSet::for_is_legal_02h()
        };

        auto data_set = std::vector<NamingRuleDataSetElement>();
        for (auto && data_set_part : data_set_parts) {
            data_set.insert(
                std::end(data_set),
                std::begin(data_set_part),
                std::end(data_set_part));
        }
        return data_set;
    }
} // namespace identifier
} // namespace sqlxx::test

#include "./definition/naming-rule-data-set.class-member.00.h++"
#include "./definition/naming-rule-data-set.class-member.01.h++"
#include "./definition/naming-rule-data-set.class-member.02.h++"

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_HXX */
