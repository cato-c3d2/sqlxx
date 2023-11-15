/*!
 * @file as-closure-data-set-element.class.h++
 */

#ifndef TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX
#define TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX

////////////////////////////////////////////////////////////////////////////////
//
// Class definition
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include <sql++/closure/as-closure.class.h++>

namespace sqlxx::test
{
inline namespace closure
{
    using sqlxx::AsClosure;

    /*!
     * @brief データセットの要素
     *
     * テスト対象のオブジェクトとテスト対象のメンバ関数の期待結果を保持する.
     */
    struct AsClosureDataSetElement
    {
        /*!
         * @brief テスト対象オブジェクト
         */
        AsClosure as_closure;

        /*!
         * @brief @c empty メンバ関数の期待結果
         */
        bool expectation_of_empty;

        /*!
         * @brief @c to_string メンバ関数の期待結果
         */
        std::string expectation_of_to_string;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out              出力ストリーム
     * @param[in] data_set_element データセットの要素
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, AsClosureDataSetElement const & data_set_element)
        -> std::ostream &;
} // namespace closure
} // namespace sqlxx::test

////////////////////////////////////////////////////////////////////////////////
//
// Class member definition
//
////////////////////////////////////////////////////////////////////////////////

namespace sqlxx::test
{
inline namespace closure
{
    // No class member function(s) and/or static data member(s).

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(
        std::ostream & out, AsClosureDataSetElement const & data_set_element)
        -> std::ostream &
    {
        return out << "{ as_closure : \"" << data_set_element.as_closure
                   << "\", expectation_of_empty : \""
                   << data_set_element.expectation_of_empty
                   << "\", expectation_of_to_string : \""
                   << data_set_element.expectation_of_to_string << "\" }";
    }
} // namespace closure
} // namespace sqlxx::test

#endif /* TEST__INCLUDE__SQLXX__CLOSURE__DATA_SET__AS_CLOSURE_DATA_SET_ELEMENT_CLASS_HXX */
