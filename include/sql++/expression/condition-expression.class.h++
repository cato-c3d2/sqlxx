/*!
 * @file condition-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX

#include <string>

#include <sql++/expression/expression.class.h++>

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
     * @brief 条件式を表現する抽象クラス
     */
    class ConditionExpression : public virtual Expression
    {
    public:
        /*!
         * @brief 純粋仮想コピーコンストラクタ
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> ConditionExpression * override = 0;
    };
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__CONDITION_EXPRESSION_CLASS_HXX
