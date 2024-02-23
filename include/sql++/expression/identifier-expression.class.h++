/*!
 * @file identifier-expression.class.h++
 */

#ifndef SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX
#define SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX

#include <string>

#include <sql++/expression/comparison-operable.class.h++>
#include <sql++/expression/condition-expression.class.h++>
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
     * @brief 識別子式（式中の識別子）を表現するクラス
     *
     * 本コードベースでは式中の識別子を「識別子式」と呼称する。 @n
     */
    class IdentifierExpression :
        public virtual Expression,
        public virtual ComparisonOperable
    {
    public:
        /*!
         * @brief 識別子の名称の型
         */
        using NameType = std::string;

    public:
        /*!
         * @brief 識別子の名称の初期値
         */
        static NameType initial_name;

    public:
        /*!
         * @brief デフォルトコンストラクタ
         */
        IdentifierExpression();

        /*!
         * @brief コンストラクタ
         *
         * @param[in] name 識別子の名称
         */
        IdentifierExpression(NameType name);

        /*!
         * @brief デストラクタ
         */
        virtual ~IdentifierExpression() override = default;

        /*!
         * @brief 識別子の名称を取得する
         *
         * @return 識別子の名称
         */
        auto name() const -> NameType;

        /*!
         * @brief 識別子の名称を設定する
         *
         * @param[in] name 識別子の名称
         *
         * @return このオブジェクトの参照
         */
        auto name(NameType name) -> IdentifierExpression &;

        /*!
         * @brief このオブジェクトの文字列表現を返却する
         *
         * @return このオブジェクトの文字列表現
         */
        auto to_string() const -> std::string;

        /*!
         * @brief この式の文字列表現を返却する
         *
         * @return この式の文字列表現
         */
        virtual auto evaluate() const -> std::string override;

        /*!
         * @brief このオブジェクトを複製する
         *
         * @return 複製したオブジェクトのポインタ
         */
        virtual auto clone() const -> IdentifierExpression const * override;

    private:
        /*!
         * @brief 識別子の名称
         */
        NameType _name;
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /*!
     * @brief ストリーム出力演算
     *
     * @param[in] out                   出力ストリーム
     * @param[in] identifier_expression 識別子式のオブジェクト
     *
     * @return 出力ストリーム
     */
    auto operator<<(
        std::ostream & out, IdentifierExpression const identifier_expression)
        -> std::ostream &;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Class member definition
    //
    ////////////////////////////////////////////////////////////////////////////

    IdentifierExpression::NameType IdentifierExpression::initial_name = "";

    IdentifierExpression::IdentifierExpression()
        : IdentifierExpression(initial_name)
    {}

    IdentifierExpression::IdentifierExpression(NameType name) : _name(name)
    {}

    auto IdentifierExpression::name() const -> NameType
    {
        return this->_name;
    }

    auto IdentifierExpression::name(NameType name) -> IdentifierExpression &
    {
        this->_name = name;
        return *this;
    }

    auto IdentifierExpression::to_string() const -> std::string
    {
        return this->_name;
    }

    auto IdentifierExpression::evaluate() const -> std::string
    {
        return this->to_string();
    }

    auto IdentifierExpression::clone() const -> IdentifierExpression const *
    {
        return new IdentifierExpression(*this);
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    auto operator<<(
        std::ostream & out, IdentifierExpression const identifier_expression)
        -> std::ostream &
    {
        out << identifier_expression.to_string();
        return out;
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__IDENTIFIER_EXPRESSION_CLASS_HXX
