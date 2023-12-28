/*!
 * @file sql++.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX_TEST_CASE_HXX

/*!
 * @namespace sqlxx::test
 *
 * @brief @c sql++ のユニットテストに関する名前空間
 */
namespace sqlxx::test
{
/*!
 * @namespace sqlxx::test::identifier
 *
 * @brief SQL の識別子 ( identifier ) のユニットテストに関するインライン名前空間
 */
inline namespace identifier
{}

/*!
 * @namespace sqlxx::test::clause
 *
 * @brief SQL の句 ( clause ) のユニットテストに関するインライン名前空間
 */
inline namespace clause
{}

/*!
 * @namespace sqlxx::test::statement
 *
 * @brief SQL の文 ( statement ) のユニットテストに関するインライン名前空間
 */
inline namespace statement
{}
} // namespace sqlxx::test

// clang-format off
#include "./sql++/identifier/column-identifier.class.test-case.h++"
#include "./sql++/identifier/table-identifier.class.test-case.h++"
#include "./sql++/identifier/naming-rule.class.test-case.h++"
#include "./sql++/clause/as-clause.class.test-case.h++"
#include "./sql++/clause/select-clause.class.test-case.h++"
#include "./sql++/clause/from-clause.class.test-case.h++"
#include "./sql++/statement/select-statement.class.test-case.h++"
// clang-format on

#endif /* TEST__INCLUDE__SQLXX_TEST_CASE_HXX */
