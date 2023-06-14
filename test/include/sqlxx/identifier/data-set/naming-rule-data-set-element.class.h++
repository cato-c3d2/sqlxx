/*!
 * @file naming-rule-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_ELEMENT_CLASS_HXX

#include <iostream>
#include <string>

#include <sql++/identifier/naming-rule.class.h++>

namespace sqlxx::test
{

using sqlxx::identifier::NamingRule;

/*!
 * @brief データセットの要素
 *
 * テスト対象関数に指定する引数と返却される論理値の期待結果を保持する.
 */
struct NamingRuleDataSetElement
{
    /*!
     * @brief テスト対象関数に指定する引数
     */
    std::string argument_of_is_legal;

    /*!
     * @brief 返却される論理値の期待結果
     */
    bool expectation_of_is_legal;
};

/**
 * @brief ストリーム出力演算
 *
 * @param[in] out              出力ストリーム
 * @param[in] data_set_element データセットの要素
 *
 * @return 出力ストリーム
 */
auto operator<<(
    std::ostream & out, NamingRuleDataSetElement const & data_set_element)
    -> std::ostream &
{
    return out << "{ argument_of_is_legal : \""
               << data_set_element.argument_of_is_legal
               << "\", expectation_of_is_legal : \""
               << data_set_element.expectation_of_is_legal << "\" }";
}

} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__IDENTIFIER__DATA_SET__NAMING_RULE_DATA_SET_ELEMENT_CLASS_HXX */
