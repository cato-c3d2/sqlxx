/*!
 * @file from-clause.class.test-case.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLAUSE__FROM_CLAUSE_CLASS_TEST_CASE_HXX
#define TEST__INCLUDE__SQLXX__CLAUSE__FROM_CLAUSE_CLASS_TEST_CASE_HXX

#include <string>

#include <boost/test/data/monomorphic.hpp>
#include <boost/test/data/test_case.hpp>

#include <sql++/clause/from-clause.class.h++>
#include <sql++/identifier/table-identifier.class.h++>

#include "./data-set/from-clause-data-set.class.h++"

////////////////////////////////////////////////////////////////////////////////
//
// Test case definition
//
////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(namespace__sqlxx__clause)

BOOST_AUTO_TEST_SUITE(class__FromClause)

using sqlxx::FromClause;
using sqlxx::TableIdentifier;
using sqlxx::test::FromClauseDataSet;

/*!
 * @brief テストパターン :
 *        @c FromClause オブジェクトがコピー代入可能であることを検証する
 *
 * @see sqlxx::clause::FromClause テスト対象クラス
 */
BOOST_AUTO_TEST_CASE(copy_assignable)
{
    // clang-format off
    FromClause const source      = {}; // コピー元のオブジェクト
    FromClause       destination = {   // コピー先のオブジェクト
        TableIdentifier { "people" }.as({ "p" })};
    // clang-format on

    // 二つのオブジェクトは等価ではないこと
    BOOST_CHECK(source.to_string() != destination.to_string());

    // コピー元のオブジェクトをコピー先のオブジェクトをコピー代入する
    destination = source;

    // 二つのオブジェクトは等価であること
    BOOST_CHECK(source.to_string() == destination.to_string());

    // 二つのオブジェクトのアドレスは異なること
    BOOST_CHECK(std::addressof(source) != std::addressof(destination));
}

/*!
 * @brief テストパターン :
 *        様々な @c FromClause オブジェクトに対して @c empty メンバ関数を呼び出す
 *
 * @see sqlxx::clause::FromClause               テスト対象クラス
 * @see sqlxx::clause::FromClause::empty()      テスト対象メンバ関数
 * @see FromClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    empty,
    boost::unit_test::data::make(FromClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    FromClause const from_clause = data_set_element.from_clause;

    // テスト対象メンバ関数の期待結果
    bool const expectation = data_set_element.expectation_of_empty;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(from_clause.empty(), expectation);
}

/*!
 * @brief テストパターン :
 *        様々な @c FromClause オブジェクトに対して @c to_string メンバ関数を呼び出す
 *
 * @see sqlxx::clause::FromClause               テスト対象クラス
 * @see sqlxx::clause::FromClause::to_string()  テスト対象メンバ関数
 * @see FromClauseDataSet::for_some_test_case() データセット
 */
BOOST_DATA_TEST_CASE(
    to_string,
    boost::unit_test::data::make(FromClauseDataSet::for_some_test_case()),
    data_set_element)
{
    // テスト対象オブジェクト
    FromClause const from_clause = data_set_element.from_clause;

    // テスト対象メンバ関数の期待結果
    std::string const expectation = data_set_element.expectation_of_to_string;

    // テスト対象メンバ関数の実行結果と期待結果が一致すること
    BOOST_CHECK_EQUAL(from_clause.to_string(), expectation);
}

BOOST_AUTO_TEST_SUITE_END(/* class__FromClause */)

BOOST_AUTO_TEST_SUITE_END(/* namespace__sqlxx__clause */)

#endif /* TEST__INCLUDE__SQLXX__CLAUSE__FROM_CLAUSE_CLASS_TEST_CASE_HXX */
