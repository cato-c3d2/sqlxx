/*!
 * @file naming-rule.data-set.h++
 */

#ifndef TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_HXX
#define TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_HXX

#include <iterator>
#include <vector>

#include "./naming-rule.data-set-element.class.h++"
#include "./naming-rule.data-set.00.h++"
#include "./naming-rule.data-set.01.h++"
#include "./naming-rule.data-set.02.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__specification)

BOOST_AUTO_TEST_SUITE(class__NamingRule)

/*!
 * @brief  データセットを返却する
 *
 * @return データセット
 *
 * @see sqlxx::specification::NamingRule             テスト対象クラス
 * @see sqlxx::specification::NamingRule::is_legal() テスト対象メンバ関数
 */
auto data_set_for_is_legal() -> std::vector<DataSetElement>
{
    std::vector<std::vector<DataSetElement>> data_set_parts = {
        // clang-format off
        data_set_for_is_legal_(),
        data_set_for_is_legal_00(),
        data_set_for_is_legal_01A(),
        data_set_for_is_legal_01a(),
        data_set_for_is_legal_01d(),
        data_set_for_is_legal_01s(),
        data_set_for_is_legal_01x(),
        data_set_for_is_legal_01z(),
        data_set_for_is_legal_02A(),
        data_set_for_is_legal_02a(),
        data_set_for_is_legal_02c(),
        data_set_for_is_legal_02d(),
        data_set_for_is_legal_02e(),
        data_set_for_is_legal_02f(),
        data_set_for_is_legal_02g(),
        data_set_for_is_legal_02h()
        // clang-format on
    };

    auto data_set = std::vector<DataSetElement>();
    for (auto && data_set_part : data_set_parts) {
        data_set.insert(
            std::end(data_set),
            std::begin(data_set_part),
            std::end(data_set_part));
    }
    return data_set;
}

BOOST_AUTO_TEST_SUITE_END(/* class__NamingRule */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__specification */)

#endif /* TEST__INCLUDE__SQLXX__SPECIFICATION__DATA_SET__NAMING_RULE_DATA_SET_HXX */
