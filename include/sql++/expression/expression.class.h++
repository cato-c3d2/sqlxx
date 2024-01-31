/*!
 * @file expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__EXPRESSION_CLASS_HXX

#include <string>

namespace sqlxx
{
inline namespace expression
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // Class definition
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief 式を表現する抽象クラス
     */
    class Expression
    {
    public:
        /*!
         * @brief デストラクタ
         */
        virtual ~Expression() = 0;

        /*!
         * @brief オブジェクトの文字列表現を返却する
         *
         * @return オブジェクトの文字列表現
         */
        virtual auto evaluate() const -> std::string = 0;

        /*!
         * @brief オブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> Expression const * = 0;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    // NOTE 純粋仮想デストラクタには定義が必要である点に注意されたし。
    Expression::~Expression()
    {}
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__EXPRESSION_CLASS_HXX
