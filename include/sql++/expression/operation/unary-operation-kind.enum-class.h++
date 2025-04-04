/*!
 * @file unary-operation-kind.enum-class.h++
 */

#ifndef SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_KIND_ENUM_CLASS_HXX
#define SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_KIND_ENUM_CLASS_HXX

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

    /**
     * @brief ≪単項演算種別≫を定義する列挙型
     */
    enum class UnaryOperationKind
    {
        /**
         * @brief ≪演算種別未定≫
         *
         * 演算の種類が未定である場合等に使用する。 @n
         */
        None = 0,

        /**
         * @brief ≪論理否定演算子≫
         */
        LogicalNot,
    };

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function declaration
    //
    ////////////////////////////////////////////////////////////////////////////

    /**
     * @brief ≪単項演算種別≫の文字列表現を返却する
     *
     * @param[in] operation_kind 文字列に変換する≪単項演算種別≫
     *
     * @return @c operation_kind の文字列表現
     */
    auto to_string(UnaryOperationKind operation_kind) -> std::string;

    ////////////////////////////////////////////////////////////////////////////
    //
    // Free function definition
    //
    ////////////////////////////////////////////////////////////////////////////

    inline namespace
    {
        /*!
         * @brief 各種≪単項演算種別≫の文字列表現を定義するクラス
         *
         * 各種≪単項演算種別≫の文字列表現は
         * @c sqlxx::expression::to_string(UnaryOperationKind)
         * を使用して取得する想定のため、このクラスは外部に公開しない。 @n
         * （そのために無名名前空間内に定義している。） @n
         */
        class UnaryOperatorSymbol
        {
        public:
            /**
             * @brief 演算子のキーワード : ≪論理否定演算≫
             */
            static constexpr auto LOGICAL_NOT = "NOT";
        };
    } // namespace

    auto to_string(UnaryOperationKind operation_kind) -> std::string
    {
        switch (operation_kind) {
        case UnaryOperationKind::LogicalNot:
            return UnaryOperatorSymbol::LOGICAL_NOT;
        case UnaryOperationKind::None:
        default:
            return "";
        }
    }
} // namespace expression
} // namespace sqlxx

#endif // SQLXX__EXPRESSION__OPERATION__UNARY_OPERATION_KIND_ENUM_CLASS_HXX
