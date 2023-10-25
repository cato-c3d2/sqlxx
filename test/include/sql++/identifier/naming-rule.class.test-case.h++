/*!
 * @file naming-rule.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__NAMING_RULE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__NAMING_RULE_CLASS_TEST_CASE_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/identifier/naming-rule.class.h++>

#include "./data-set/naming-rule-data-set.class.h++"

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__identifier)

BOOST_AUTO_TEST_SUITE(class__NamingRule)

using sqlxx::identifier::NamingRule;
using sqlxx::test::NamingRuleDataSet;

/*!
 * @brief テストパターン :
 *        様々な文字列に対して命名規則に合致しているか判定する
 *
 * @see sqlxx::identifier::NamingRule             テスト対象クラス
 * @see sqlxx::identifier::NamingRule::is_legal() テスト対象メンバ関数
 * @see NamingRuleDataSet::for_is_legal()         データセット生成メンバ関数
 */
BOOST_DATA_TEST_CASE(
    is_legal,
    boost::unit_test::data::make(NamingRuleDataSet::for_is_legal()),
    data_set_element)
{
    // テスト対象関数に指定する引数
    std::string const identifier = data_set_element.argument_of_is_legal;

    // テスト対象関数から返却される論理値の期待結果
    bool const expectation = data_set_element.expectation_of_is_legal;

    // テスト対象関数から返却された論理値が期待結果と一致すること
    BOOST_CHECK_EQUAL(NamingRule::is_legal(identifier), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__NamingRule */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__identifier */)

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__NAMING_RULE_CLASS_TEST_CASE_HXX */
