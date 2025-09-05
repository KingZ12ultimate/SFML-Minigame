//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     LdtkJson data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

#include <optional>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json& j, const std::shared_ptr<T>& opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json& j) {
            if (j.is_null()) return std::make_shared<T>(); else return std::make_shared<T>(j.get<T>());
        }
    };
    template <typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(json& j, const std::optional<T>& opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::optional<T> from_json(const json& j) {
            if (j.is_null()) return std::make_optional<T>(); else return std::make_optional<T>(j.get<T>());
        }
    };
}
#endif

namespace quicktype {
    using nlohmann::json;

#ifndef NLOHMANN_UNTYPED_quicktype_HELPER
#define NLOHMANN_UNTYPED_quicktype_HELPER
    inline json get_untyped(const json& j, const char* property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json& j, std::string property) {
        return get_untyped(j, property.data());
    }
#endif

#ifndef NLOHMANN_OPTIONAL_quicktype_HELPER
#define NLOHMANN_OPTIONAL_quicktype_HELPER
    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json& j, const char* property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_heap_optional(const json& j, std::string property) {
        return get_heap_optional<T>(j, property.data());
    }
    template <typename T>
    inline std::optional<T> get_stack_optional(const json& j, const char* property) {
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
            return j.at(property).get<std::optional<T>>();
        }
        return std::optional<T>();
    }

    template <typename T>
    inline std::optional<T> get_stack_optional(const json& j, std::string property) {
        return get_stack_optional<T>(j, property.data());
    }
#endif

    class Icon {
    public:
        Icon() = default;
        virtual ~Icon() = default;

    private:
        int64_t tileset_uid;
        int64_t x;
        int64_t y;
        int64_t w;
        int64_t h;

    public:
        const int64_t& get_tileset_uid() const { return tileset_uid; }
        int64_t& get_mutable_tileset_uid() { return tileset_uid; }
        void set_tileset_uid(const int64_t& value) { this->tileset_uid = value; }

        const int64_t& get_x() const { return x; }
        int64_t& get_mutable_x() { return x; }
        void set_x(const int64_t& value) { this->x = value; }

        const int64_t& get_y() const { return y; }
        int64_t& get_mutable_y() { return y; }
        void set_y(const int64_t& value) { this->y = value; }

        const int64_t& get_w() const { return w; }
        int64_t& get_mutable_w() { return w; }
        void set_w(const int64_t& value) { this->w = value; }

        const int64_t& get_h() const { return h; }
        int64_t& get_mutable_h() { return h; }
        void set_h(const int64_t& value) { this->h = value; }
    };

    enum class ImageExportMode : int { NONE };

    enum class TileMode : int { SINGLE };

    class Rule {
    public:
        Rule() = default;
        virtual ~Rule() = default;

    private:
        int64_t uid;
        bool active;
        int64_t size;
        std::vector<std::vector<int64_t>> tile_rects_ids;
        int64_t alpha;
        double chance;
        bool break_on_match;
        std::vector<int64_t> pattern;
        bool flip_x;
        bool flip_y;
        int64_t x_modulo;
        int64_t y_modulo;
        int64_t x_offset;
        int64_t y_offset;
        int64_t tile_x_offset;
        int64_t tile_y_offset;
        int64_t tile_random_x_min;
        int64_t tile_random_x_max;
        int64_t tile_random_y_min;
        int64_t tile_random_y_max;
        ImageExportMode checker;
        TileMode tile_mode;
        int64_t pivot_x;
        int64_t pivot_y;
        nlohmann::json out_of_bounds_value;
        bool invalidated;
        bool perlin_active;
        int64_t perlin_seed;
        double perlin_scale;
        int64_t perlin_octaves;

    public:
        const int64_t& get_uid() const { return uid; }
        int64_t& get_mutable_uid() { return uid; }
        void set_uid(const int64_t& value) { this->uid = value; }

        const bool& get_active() const { return active; }
        bool& get_mutable_active() { return active; }
        void set_active(const bool& value) { this->active = value; }

        const int64_t& get_size() const { return size; }
        int64_t& get_mutable_size() { return size; }
        void set_size(const int64_t& value) { this->size = value; }

        const std::vector<std::vector<int64_t>>& get_tile_rects_ids() const { return tile_rects_ids; }
        std::vector<std::vector<int64_t>>& get_mutable_tile_rects_ids() { return tile_rects_ids; }
        void set_tile_rects_ids(const std::vector<std::vector<int64_t>>& value) { this->tile_rects_ids = value; }

        const int64_t& get_alpha() const { return alpha; }
        int64_t& get_mutable_alpha() { return alpha; }
        void set_alpha(const int64_t& value) { this->alpha = value; }

        const double& get_chance() const { return chance; }
        double& get_mutable_chance() { return chance; }
        void set_chance(const double& value) { this->chance = value; }

        const bool& get_break_on_match() const { return break_on_match; }
        bool& get_mutable_break_on_match() { return break_on_match; }
        void set_break_on_match(const bool& value) { this->break_on_match = value; }

        const std::vector<int64_t>& get_pattern() const { return pattern; }
        std::vector<int64_t>& get_mutable_pattern() { return pattern; }
        void set_pattern(const std::vector<int64_t>& value) { this->pattern = value; }

        const bool& get_flip_x() const { return flip_x; }
        bool& get_mutable_flip_x() { return flip_x; }
        void set_flip_x(const bool& value) { this->flip_x = value; }

        const bool& get_flip_y() const { return flip_y; }
        bool& get_mutable_flip_y() { return flip_y; }
        void set_flip_y(const bool& value) { this->flip_y = value; }

        const int64_t& get_x_modulo() const { return x_modulo; }
        int64_t& get_mutable_x_modulo() { return x_modulo; }
        void set_x_modulo(const int64_t& value) { this->x_modulo = value; }

        const int64_t& get_y_modulo() const { return y_modulo; }
        int64_t& get_mutable_y_modulo() { return y_modulo; }
        void set_y_modulo(const int64_t& value) { this->y_modulo = value; }

        const int64_t& get_x_offset() const { return x_offset; }
        int64_t& get_mutable_x_offset() { return x_offset; }
        void set_x_offset(const int64_t& value) { this->x_offset = value; }

        const int64_t& get_y_offset() const { return y_offset; }
        int64_t& get_mutable_y_offset() { return y_offset; }
        void set_y_offset(const int64_t& value) { this->y_offset = value; }

        const int64_t& get_tile_x_offset() const { return tile_x_offset; }
        int64_t& get_mutable_tile_x_offset() { return tile_x_offset; }
        void set_tile_x_offset(const int64_t& value) { this->tile_x_offset = value; }

        const int64_t& get_tile_y_offset() const { return tile_y_offset; }
        int64_t& get_mutable_tile_y_offset() { return tile_y_offset; }
        void set_tile_y_offset(const int64_t& value) { this->tile_y_offset = value; }

        const int64_t& get_tile_random_x_min() const { return tile_random_x_min; }
        int64_t& get_mutable_tile_random_x_min() { return tile_random_x_min; }
        void set_tile_random_x_min(const int64_t& value) { this->tile_random_x_min = value; }

        const int64_t& get_tile_random_x_max() const { return tile_random_x_max; }
        int64_t& get_mutable_tile_random_x_max() { return tile_random_x_max; }
        void set_tile_random_x_max(const int64_t& value) { this->tile_random_x_max = value; }

        const int64_t& get_tile_random_y_min() const { return tile_random_y_min; }
        int64_t& get_mutable_tile_random_y_min() { return tile_random_y_min; }
        void set_tile_random_y_min(const int64_t& value) { this->tile_random_y_min = value; }

        const int64_t& get_tile_random_y_max() const { return tile_random_y_max; }
        int64_t& get_mutable_tile_random_y_max() { return tile_random_y_max; }
        void set_tile_random_y_max(const int64_t& value) { this->tile_random_y_max = value; }

        const ImageExportMode& get_checker() const { return checker; }
        ImageExportMode& get_mutable_checker() { return checker; }
        void set_checker(const ImageExportMode& value) { this->checker = value; }

        const TileMode& get_tile_mode() const { return tile_mode; }
        TileMode& get_mutable_tile_mode() { return tile_mode; }
        void set_tile_mode(const TileMode& value) { this->tile_mode = value; }

        const int64_t& get_pivot_x() const { return pivot_x; }
        int64_t& get_mutable_pivot_x() { return pivot_x; }
        void set_pivot_x(const int64_t& value) { this->pivot_x = value; }

        const int64_t& get_pivot_y() const { return pivot_y; }
        int64_t& get_mutable_pivot_y() { return pivot_y; }
        void set_pivot_y(const int64_t& value) { this->pivot_y = value; }

        const nlohmann::json& get_out_of_bounds_value() const { return out_of_bounds_value; }
        nlohmann::json& get_mutable_out_of_bounds_value() { return out_of_bounds_value; }
        void set_out_of_bounds_value(const nlohmann::json& value) { this->out_of_bounds_value = value; }

        const bool& get_invalidated() const { return invalidated; }
        bool& get_mutable_invalidated() { return invalidated; }
        void set_invalidated(const bool& value) { this->invalidated = value; }

        const bool& get_perlin_active() const { return perlin_active; }
        bool& get_mutable_perlin_active() { return perlin_active; }
        void set_perlin_active(const bool& value) { this->perlin_active = value; }

        const int64_t& get_perlin_seed() const { return perlin_seed; }
        int64_t& get_mutable_perlin_seed() { return perlin_seed; }
        void set_perlin_seed(const int64_t& value) { this->perlin_seed = value; }

        const double& get_perlin_scale() const { return perlin_scale; }
        double& get_mutable_perlin_scale() { return perlin_scale; }
        void set_perlin_scale(const double& value) { this->perlin_scale = value; }

        const int64_t& get_perlin_octaves() const { return perlin_octaves; }
        int64_t& get_mutable_perlin_octaves() { return perlin_octaves; }
        void set_perlin_octaves(const int64_t& value) { this->perlin_octaves = value; }
    };

    class AutoRuleGroup {
    public:
        AutoRuleGroup() = default;
        virtual ~AutoRuleGroup() = default;

    private:
        int64_t uid;
        std::string name;
        std::optional<std::string> color;
        Icon icon;
        bool active;
        bool is_optional;
        std::vector<Rule> rules;
        bool uses_wizard;
        std::vector<nlohmann::json> required_biome_values;
        int64_t biome_requirement_mode;

    public:
        const int64_t& get_uid() const { return uid; }
        int64_t& get_mutable_uid() { return uid; }
        void set_uid(const int64_t& value) { this->uid = value; }

        const std::string& get_name() const { return name; }
        std::string& get_mutable_name() { return name; }
        void set_name(const std::string& value) { this->name = value; }

        std::optional<std::string> get_color() const { return color; }
        void set_color(std::optional<std::string> value) { this->color = value; }

        const Icon& get_icon() const { return icon; }
        Icon& get_mutable_icon() { return icon; }
        void set_icon(const Icon& value) { this->icon = value; }

        const bool& get_active() const { return active; }
        bool& get_mutable_active() { return active; }
        void set_active(const bool& value) { this->active = value; }

        const bool& get_is_optional() const { return is_optional; }
        bool& get_mutable_is_optional() { return is_optional; }
        void set_is_optional(const bool& value) { this->is_optional = value; }

        const std::vector<Rule>& get_rules() const { return rules; }
        std::vector<Rule>& get_mutable_rules() { return rules; }
        void set_rules(const std::vector<Rule>& value) { this->rules = value; }

        const bool& get_uses_wizard() const { return uses_wizard; }
        bool& get_mutable_uses_wizard() { return uses_wizard; }
        void set_uses_wizard(const bool& value) { this->uses_wizard = value; }

        const std::vector<nlohmann::json>& get_required_biome_values() const { return required_biome_values; }
        std::vector<nlohmann::json>& get_mutable_required_biome_values() { return required_biome_values; }
        void set_required_biome_values(const std::vector<nlohmann::json>& value) { this->required_biome_values = value; }

        const int64_t& get_biome_requirement_mode() const { return biome_requirement_mode; }
        int64_t& get_mutable_biome_requirement_mode() { return biome_requirement_mode; }
        void set_biome_requirement_mode(const int64_t& value) { this->biome_requirement_mode = value; }
    };

    class IntGridValue {
    public:
        IntGridValue() = default;
        virtual ~IntGridValue() = default;

    private:
        int64_t value;
        std::string identifier;
        std::string color;
        Icon tile;
        int64_t group_uid;

    public:
        const int64_t& get_value() const { return value; }
        int64_t& get_mutable_value() { return value; }
        void set_value(const int64_t& value) { this->value = value; }

        const std::string& get_identifier() const { return identifier; }
        std::string& get_mutable_identifier() { return identifier; }
        void set_identifier(const std::string& value) { this->identifier = value; }

        const std::string& get_color() const { return color; }
        std::string& get_mutable_color() { return color; }
        void set_color(const std::string& value) { this->color = value; }

        const Icon& get_tile() const { return tile; }
        Icon& get_mutable_tile() { return tile; }
        void set_tile(const Icon& value) { this->tile = value; }

        const int64_t& get_group_uid() const { return group_uid; }
        int64_t& get_mutable_group_uid() { return group_uid; }
        void set_group_uid(const int64_t& value) { this->group_uid = value; }
    };

    class Layer {
    public:
        Layer() = default;
        virtual ~Layer() = default;

    private:
        std::string type;
        std::string identifier;
        std::string layer_type;
        int64_t uid;
        nlohmann::json doc;
        nlohmann::json ui_color;
        int64_t grid_size;
        int64_t guide_grid_wid;
        int64_t guide_grid_hei;
        int64_t display_opacity;
        int64_t inactive_opacity;
        bool hide_in_list;
        bool hide_fields_when_inactive;
        bool can_select_when_inactive;
        bool render_in_world_view;
        int64_t px_offset_x;
        int64_t px_offset_y;
        int64_t parallax_factor_x;
        int64_t parallax_factor_y;
        bool parallax_scaling;
        std::vector<nlohmann::json> required_tags;
        std::vector<nlohmann::json> excluded_tags;
        nlohmann::json auto_tiles_killed_by_other_layer_uid;
        std::vector<nlohmann::json> ui_filter_tags;
        bool use_async_render;
        std::vector<IntGridValue> int_grid_values;
        std::vector<nlohmann::json> int_grid_values_groups;
        std::vector<AutoRuleGroup> auto_rule_groups;
        nlohmann::json auto_source_layer_def_uid;
        int64_t tileset_def_uid;
        int64_t tile_pivot_x;
        int64_t tile_pivot_y;
        nlohmann::json biome_field_uid;

    public:
        const std::string& get_type() const { return type; }
        std::string& get_mutable_type() { return type; }
        void set_type(const std::string& value) { this->type = value; }

        const std::string& get_identifier() const { return identifier; }
        std::string& get_mutable_identifier() { return identifier; }
        void set_identifier(const std::string& value) { this->identifier = value; }

        const std::string& get_layer_type() const { return layer_type; }
        std::string& get_mutable_layer_type() { return layer_type; }
        void set_layer_type(const std::string& value) { this->layer_type = value; }

        const int64_t& get_uid() const { return uid; }
        int64_t& get_mutable_uid() { return uid; }
        void set_uid(const int64_t& value) { this->uid = value; }

        const nlohmann::json& get_doc() const { return doc; }
        nlohmann::json& get_mutable_doc() { return doc; }
        void set_doc(const nlohmann::json& value) { this->doc = value; }

        const nlohmann::json& get_ui_color() const { return ui_color; }
        nlohmann::json& get_mutable_ui_color() { return ui_color; }
        void set_ui_color(const nlohmann::json& value) { this->ui_color = value; }

        const int64_t& get_grid_size() const { return grid_size; }
        int64_t& get_mutable_grid_size() { return grid_size; }
        void set_grid_size(const int64_t& value) { this->grid_size = value; }

        const int64_t& get_guide_grid_wid() const { return guide_grid_wid; }
        int64_t& get_mutable_guide_grid_wid() { return guide_grid_wid; }
        void set_guide_grid_wid(const int64_t& value) { this->guide_grid_wid = value; }

        const int64_t& get_guide_grid_hei() const { return guide_grid_hei; }
        int64_t& get_mutable_guide_grid_hei() { return guide_grid_hei; }
        void set_guide_grid_hei(const int64_t& value) { this->guide_grid_hei = value; }

        const int64_t& get_display_opacity() const { return display_opacity; }
        int64_t& get_mutable_display_opacity() { return display_opacity; }
        void set_display_opacity(const int64_t& value) { this->display_opacity = value; }

        const int64_t& get_inactive_opacity() const { return inactive_opacity; }
        int64_t& get_mutable_inactive_opacity() { return inactive_opacity; }
        void set_inactive_opacity(const int64_t& value) { this->inactive_opacity = value; }

        const bool& get_hide_in_list() const { return hide_in_list; }
        bool& get_mutable_hide_in_list() { return hide_in_list; }
        void set_hide_in_list(const bool& value) { this->hide_in_list = value; }

        const bool& get_hide_fields_when_inactive() const { return hide_fields_when_inactive; }
        bool& get_mutable_hide_fields_when_inactive() { return hide_fields_when_inactive; }
        void set_hide_fields_when_inactive(const bool& value) { this->hide_fields_when_inactive = value; }

        const bool& get_can_select_when_inactive() const { return can_select_when_inactive; }
        bool& get_mutable_can_select_when_inactive() { return can_select_when_inactive; }
        void set_can_select_when_inactive(const bool& value) { this->can_select_when_inactive = value; }

        const bool& get_render_in_world_view() const { return render_in_world_view; }
        bool& get_mutable_render_in_world_view() { return render_in_world_view; }
        void set_render_in_world_view(const bool& value) { this->render_in_world_view = value; }

        const int64_t& get_px_offset_x() const { return px_offset_x; }
        int64_t& get_mutable_px_offset_x() { return px_offset_x; }
        void set_px_offset_x(const int64_t& value) { this->px_offset_x = value; }

        const int64_t& get_px_offset_y() const { return px_offset_y; }
        int64_t& get_mutable_px_offset_y() { return px_offset_y; }
        void set_px_offset_y(const int64_t& value) { this->px_offset_y = value; }

        const int64_t& get_parallax_factor_x() const { return parallax_factor_x; }
        int64_t& get_mutable_parallax_factor_x() { return parallax_factor_x; }
        void set_parallax_factor_x(const int64_t& value) { this->parallax_factor_x = value; }

        const int64_t& get_parallax_factor_y() const { return parallax_factor_y; }
        int64_t& get_mutable_parallax_factor_y() { return parallax_factor_y; }
        void set_parallax_factor_y(const int64_t& value) { this->parallax_factor_y = value; }

        const bool& get_parallax_scaling() const { return parallax_scaling; }
        bool& get_mutable_parallax_scaling() { return parallax_scaling; }
        void set_parallax_scaling(const bool& value) { this->parallax_scaling = value; }

        const std::vector<nlohmann::json>& get_required_tags() const { return required_tags; }
        std::vector<nlohmann::json>& get_mutable_required_tags() { return required_tags; }
        void set_required_tags(const std::vector<nlohmann::json>& value) { this->required_tags = value; }

        const std::vector<nlohmann::json>& get_excluded_tags() const { return excluded_tags; }
        std::vector<nlohmann::json>& get_mutable_excluded_tags() { return excluded_tags; }
        void set_excluded_tags(const std::vector<nlohmann::json>& value) { this->excluded_tags = value; }

        const nlohmann::json& get_auto_tiles_killed_by_other_layer_uid() const { return auto_tiles_killed_by_other_layer_uid; }
        nlohmann::json& get_mutable_auto_tiles_killed_by_other_layer_uid() { return auto_tiles_killed_by_other_layer_uid; }
        void set_auto_tiles_killed_by_other_layer_uid(const nlohmann::json& value) { this->auto_tiles_killed_by_other_layer_uid = value; }

        const std::vector<nlohmann::json>& get_ui_filter_tags() const { return ui_filter_tags; }
        std::vector<nlohmann::json>& get_mutable_ui_filter_tags() { return ui_filter_tags; }
        void set_ui_filter_tags(const std::vector<nlohmann::json>& value) { this->ui_filter_tags = value; }

        const bool& get_use_async_render() const { return use_async_render; }
        bool& get_mutable_use_async_render() { return use_async_render; }
        void set_use_async_render(const bool& value) { this->use_async_render = value; }

        const std::vector<IntGridValue>& get_int_grid_values() const { return int_grid_values; }
        std::vector<IntGridValue>& get_mutable_int_grid_values() { return int_grid_values; }
        void set_int_grid_values(const std::vector<IntGridValue>& value) { this->int_grid_values = value; }

        const std::vector<nlohmann::json>& get_int_grid_values_groups() const { return int_grid_values_groups; }
        std::vector<nlohmann::json>& get_mutable_int_grid_values_groups() { return int_grid_values_groups; }
        void set_int_grid_values_groups(const std::vector<nlohmann::json>& value) { this->int_grid_values_groups = value; }

        const std::vector<AutoRuleGroup>& get_auto_rule_groups() const { return auto_rule_groups; }
        std::vector<AutoRuleGroup>& get_mutable_auto_rule_groups() { return auto_rule_groups; }
        void set_auto_rule_groups(const std::vector<AutoRuleGroup>& value) { this->auto_rule_groups = value; }

        const nlohmann::json& get_auto_source_layer_def_uid() const { return auto_source_layer_def_uid; }
        nlohmann::json& get_mutable_auto_source_layer_def_uid() { return auto_source_layer_def_uid; }
        void set_auto_source_layer_def_uid(const nlohmann::json& value) { this->auto_source_layer_def_uid = value; }

        const int64_t& get_tileset_def_uid() const { return tileset_def_uid; }
        int64_t& get_mutable_tileset_def_uid() { return tileset_def_uid; }
        void set_tileset_def_uid(const int64_t& value) { this->tileset_def_uid = value; }

        const int64_t& get_tile_pivot_x() const { return tile_pivot_x; }
        int64_t& get_mutable_tile_pivot_x() { return tile_pivot_x; }
        void set_tile_pivot_x(const int64_t& value) { this->tile_pivot_x = value; }

        const int64_t& get_tile_pivot_y() const { return tile_pivot_y; }
        int64_t& get_mutable_tile_pivot_y() { return tile_pivot_y; }
        void set_tile_pivot_y(const int64_t& value) { this->tile_pivot_y = value; }

        const nlohmann::json& get_biome_field_uid() const { return biome_field_uid; }
        nlohmann::json& get_mutable_biome_field_uid() { return biome_field_uid; }
        void set_biome_field_uid(const nlohmann::json& value) { this->biome_field_uid = value; }
    };

    class CachedPixelData {
    public:
        CachedPixelData() = default;
        virtual ~CachedPixelData() = default;

    private:
        std::string opaque_tiles;
        std::string average_colors;

    public:
        const std::string& get_opaque_tiles() const { return opaque_tiles; }
        std::string& get_mutable_opaque_tiles() { return opaque_tiles; }
        void set_opaque_tiles(const std::string& value) { this->opaque_tiles = value; }

        const std::string& get_average_colors() const { return average_colors; }
        std::string& get_mutable_average_colors() { return average_colors; }
        void set_average_colors(const std::string& value) { this->average_colors = value; }
    };

    enum class Mode : int { RANDOM, STAMP };

    class SavedSelection {
    public:
        SavedSelection() = default;
        virtual ~SavedSelection() = default;

    private:
        std::vector<int64_t> ids;
        Mode mode;

    public:
        const std::vector<int64_t>& get_ids() const { return ids; }
        std::vector<int64_t>& get_mutable_ids() { return ids; }
        void set_ids(const std::vector<int64_t>& value) { this->ids = value; }

        const Mode& get_mode() const { return mode; }
        Mode& get_mutable_mode() { return mode; }
        void set_mode(const Mode& value) { this->mode = value; }
    };

    class Tileset {
    public:
        Tileset() = default;
        virtual ~Tileset() = default;

    private:
        int64_t c_wid;
        int64_t c_hei;
        std::string identifier;
        int64_t uid;
        std::string rel_path;
        nlohmann::json embed_atlas;
        int64_t px_wid;
        int64_t px_hei;
        int64_t tile_grid_size;
        int64_t spacing;
        int64_t padding;
        std::vector<nlohmann::json> tags;
        nlohmann::json tags_source_enum_uid;
        std::vector<nlohmann::json> enum_tags;
        std::vector<nlohmann::json> custom_data;
        std::vector<SavedSelection> saved_selections;
        CachedPixelData cached_pixel_data;

    public:
        const int64_t& get_c_wid() const { return c_wid; }
        int64_t& get_mutable_c_wid() { return c_wid; }
        void set_c_wid(const int64_t& value) { this->c_wid = value; }

        const int64_t& get_c_hei() const { return c_hei; }
        int64_t& get_mutable_c_hei() { return c_hei; }
        void set_c_hei(const int64_t& value) { this->c_hei = value; }

        const std::string& get_identifier() const { return identifier; }
        std::string& get_mutable_identifier() { return identifier; }
        void set_identifier(const std::string& value) { this->identifier = value; }

        const int64_t& get_uid() const { return uid; }
        int64_t& get_mutable_uid() { return uid; }
        void set_uid(const int64_t& value) { this->uid = value; }

        const std::string& get_rel_path() const { return rel_path; }
        std::string& get_mutable_rel_path() { return rel_path; }
        void set_rel_path(const std::string& value) { this->rel_path = value; }

        const nlohmann::json& get_embed_atlas() const { return embed_atlas; }
        nlohmann::json& get_mutable_embed_atlas() { return embed_atlas; }
        void set_embed_atlas(const nlohmann::json& value) { this->embed_atlas = value; }

        const int64_t& get_px_wid() const { return px_wid; }
        int64_t& get_mutable_px_wid() { return px_wid; }
        void set_px_wid(const int64_t& value) { this->px_wid = value; }

        const int64_t& get_px_hei() const { return px_hei; }
        int64_t& get_mutable_px_hei() { return px_hei; }
        void set_px_hei(const int64_t& value) { this->px_hei = value; }

        const int64_t& get_tile_grid_size() const { return tile_grid_size; }
        int64_t& get_mutable_tile_grid_size() { return tile_grid_size; }
        void set_tile_grid_size(const int64_t& value) { this->tile_grid_size = value; }

        const int64_t& get_spacing() const { return spacing; }
        int64_t& get_mutable_spacing() { return spacing; }
        void set_spacing(const int64_t& value) { this->spacing = value; }

        const int64_t& get_padding() const { return padding; }
        int64_t& get_mutable_padding() { return padding; }
        void set_padding(const int64_t& value) { this->padding = value; }

        const std::vector<nlohmann::json>& get_tags() const { return tags; }
        std::vector<nlohmann::json>& get_mutable_tags() { return tags; }
        void set_tags(const std::vector<nlohmann::json>& value) { this->tags = value; }

        const nlohmann::json& get_tags_source_enum_uid() const { return tags_source_enum_uid; }
        nlohmann::json& get_mutable_tags_source_enum_uid() { return tags_source_enum_uid; }
        void set_tags_source_enum_uid(const nlohmann::json& value) { this->tags_source_enum_uid = value; }

        const std::vector<nlohmann::json>& get_enum_tags() const { return enum_tags; }
        std::vector<nlohmann::json>& get_mutable_enum_tags() { return enum_tags; }
        void set_enum_tags(const std::vector<nlohmann::json>& value) { this->enum_tags = value; }

        const std::vector<nlohmann::json>& get_custom_data() const { return custom_data; }
        std::vector<nlohmann::json>& get_mutable_custom_data() { return custom_data; }
        void set_custom_data(const std::vector<nlohmann::json>& value) { this->custom_data = value; }

        const std::vector<SavedSelection>& get_saved_selections() const { return saved_selections; }
        std::vector<SavedSelection>& get_mutable_saved_selections() { return saved_selections; }
        void set_saved_selections(const std::vector<SavedSelection>& value) { this->saved_selections = value; }

        const CachedPixelData& get_cached_pixel_data() const { return cached_pixel_data; }
        CachedPixelData& get_mutable_cached_pixel_data() { return cached_pixel_data; }
        void set_cached_pixel_data(const CachedPixelData& value) { this->cached_pixel_data = value; }
    };

    class Defs {
    public:
        Defs() = default;
        virtual ~Defs() = default;

    private:
        std::vector<Layer> layers;
        std::vector<nlohmann::json> entities;
        std::vector<Tileset> tilesets;
        std::vector<nlohmann::json> enums;
        std::vector<nlohmann::json> external_enums;
        std::vector<nlohmann::json> level_fields;

    public:
        const std::vector<Layer>& get_layers() const { return layers; }
        std::vector<Layer>& get_mutable_layers() { return layers; }
        void set_layers(const std::vector<Layer>& value) { this->layers = value; }

        const std::vector<nlohmann::json>& get_entities() const { return entities; }
        std::vector<nlohmann::json>& get_mutable_entities() { return entities; }
        void set_entities(const std::vector<nlohmann::json>& value) { this->entities = value; }

        const std::vector<Tileset>& get_tilesets() const { return tilesets; }
        std::vector<Tileset>& get_mutable_tilesets() { return tilesets; }
        void set_tilesets(const std::vector<Tileset>& value) { this->tilesets = value; }

        const std::vector<nlohmann::json>& get_enums() const { return enums; }
        std::vector<nlohmann::json>& get_mutable_enums() { return enums; }
        void set_enums(const std::vector<nlohmann::json>& value) { this->enums = value; }

        const std::vector<nlohmann::json>& get_external_enums() const { return external_enums; }
        std::vector<nlohmann::json>& get_mutable_external_enums() { return external_enums; }
        void set_external_enums(const std::vector<nlohmann::json>& value) { this->external_enums = value; }

        const std::vector<nlohmann::json>& get_level_fields() const { return level_fields; }
        std::vector<nlohmann::json>& get_mutable_level_fields() { return level_fields; }
        void set_level_fields(const std::vector<nlohmann::json>& value) { this->level_fields = value; }
    };

    class Header {
    public:
        Header() = default;
        virtual ~Header() = default;

    private:
        std::string file_type;
        std::string app;
        std::string doc;
        std::string schema;
        std::string app_author;
        std::string app_version;
        std::string url;

    public:
        const std::string& get_file_type() const { return file_type; }
        std::string& get_mutable_file_type() { return file_type; }
        void set_file_type(const std::string& value) { this->file_type = value; }

        const std::string& get_app() const { return app; }
        std::string& get_mutable_app() { return app; }
        void set_app(const std::string& value) { this->app = value; }

        const std::string& get_doc() const { return doc; }
        std::string& get_mutable_doc() { return doc; }
        void set_doc(const std::string& value) { this->doc = value; }

        const std::string& get_schema() const { return schema; }
        std::string& get_mutable_schema() { return schema; }
        void set_schema(const std::string& value) { this->schema = value; }

        const std::string& get_app_author() const { return app_author; }
        std::string& get_mutable_app_author() { return app_author; }
        void set_app_author(const std::string& value) { this->app_author = value; }

        const std::string& get_app_version() const { return app_version; }
        std::string& get_mutable_app_version() { return app_version; }
        void set_app_version(const std::string& value) { this->app_version = value; }

        const std::string& get_url() const { return url; }
        std::string& get_mutable_url() { return url; }
        void set_url(const std::string& value) { this->url = value; }
    };

    class AutoLayerTile {
    public:
        AutoLayerTile() = default;
        virtual ~AutoLayerTile() = default;

    private:
        std::vector<int64_t> px;
        std::vector<int64_t> src;
        int64_t f;
        int64_t t;
        std::vector<int64_t> d;
        int64_t a;

    public:
        const std::vector<int64_t>& get_px() const { return px; }
        std::vector<int64_t>& get_mutable_px() { return px; }
        void set_px(const std::vector<int64_t>& value) { this->px = value; }

        const std::vector<int64_t>& get_src() const { return src; }
        std::vector<int64_t>& get_mutable_src() { return src; }
        void set_src(const std::vector<int64_t>& value) { this->src = value; }

        const int64_t& get_f() const { return f; }
        int64_t& get_mutable_f() { return f; }
        void set_f(const int64_t& value) { this->f = value; }

        const int64_t& get_t() const { return t; }
        int64_t& get_mutable_t() { return t; }
        void set_t(const int64_t& value) { this->t = value; }

        const std::vector<int64_t>& get_d() const { return d; }
        std::vector<int64_t>& get_mutable_d() { return d; }
        void set_d(const std::vector<int64_t>& value) { this->d = value; }

        const int64_t& get_a() const { return a; }
        int64_t& get_mutable_a() { return a; }
        void set_a(const int64_t& value) { this->a = value; }
    };

    class LayerInstance {
    public:
        LayerInstance() = default;
        virtual ~LayerInstance() = default;

    private:
        std::string identifier;
        std::string type;
        int64_t c_wid;
        int64_t c_hei;
        int64_t grid_size;
        int64_t opacity;
        int64_t px_total_offset_x;
        int64_t px_total_offset_y;
        int64_t tileset_def_uid;
        std::string tileset_rel_path;
        std::string iid;
        int64_t level_id;
        int64_t layer_def_uid;
        int64_t px_offset_x;
        int64_t px_offset_y;
        bool visible;
        std::vector<nlohmann::json> optional_rules;
        std::vector<int64_t> int_grid_csv;
        std::vector<AutoLayerTile> auto_layer_tiles;
        int64_t seed;
        nlohmann::json override_tileset_uid;
        std::vector<nlohmann::json> grid_tiles;
        std::vector<nlohmann::json> entity_instances;

    public:
        const std::string& get_identifier() const { return identifier; }
        std::string& get_mutable_identifier() { return identifier; }
        void set_identifier(const std::string& value) { this->identifier = value; }

        const std::string& get_type() const { return type; }
        std::string& get_mutable_type() { return type; }
        void set_type(const std::string& value) { this->type = value; }

        const int64_t& get_c_wid() const { return c_wid; }
        int64_t& get_mutable_c_wid() { return c_wid; }
        void set_c_wid(const int64_t& value) { this->c_wid = value; }

        const int64_t& get_c_hei() const { return c_hei; }
        int64_t& get_mutable_c_hei() { return c_hei; }
        void set_c_hei(const int64_t& value) { this->c_hei = value; }

        const int64_t& get_grid_size() const { return grid_size; }
        int64_t& get_mutable_grid_size() { return grid_size; }
        void set_grid_size(const int64_t& value) { this->grid_size = value; }

        const int64_t& get_opacity() const { return opacity; }
        int64_t& get_mutable_opacity() { return opacity; }
        void set_opacity(const int64_t& value) { this->opacity = value; }

        const int64_t& get_px_total_offset_x() const { return px_total_offset_x; }
        int64_t& get_mutable_px_total_offset_x() { return px_total_offset_x; }
        void set_px_total_offset_x(const int64_t& value) { this->px_total_offset_x = value; }

        const int64_t& get_px_total_offset_y() const { return px_total_offset_y; }
        int64_t& get_mutable_px_total_offset_y() { return px_total_offset_y; }
        void set_px_total_offset_y(const int64_t& value) { this->px_total_offset_y = value; }

        const int64_t& get_tileset_def_uid() const { return tileset_def_uid; }
        int64_t& get_mutable_tileset_def_uid() { return tileset_def_uid; }
        void set_tileset_def_uid(const int64_t& value) { this->tileset_def_uid = value; }

        const std::string& get_tileset_rel_path() const { return tileset_rel_path; }
        std::string& get_mutable_tileset_rel_path() { return tileset_rel_path; }
        void set_tileset_rel_path(const std::string& value) { this->tileset_rel_path = value; }

        const std::string& get_iid() const { return iid; }
        std::string& get_mutable_iid() { return iid; }
        void set_iid(const std::string& value) { this->iid = value; }

        const int64_t& get_level_id() const { return level_id; }
        int64_t& get_mutable_level_id() { return level_id; }
        void set_level_id(const int64_t& value) { this->level_id = value; }

        const int64_t& get_layer_def_uid() const { return layer_def_uid; }
        int64_t& get_mutable_layer_def_uid() { return layer_def_uid; }
        void set_layer_def_uid(const int64_t& value) { this->layer_def_uid = value; }

        const int64_t& get_px_offset_x() const { return px_offset_x; }
        int64_t& get_mutable_px_offset_x() { return px_offset_x; }
        void set_px_offset_x(const int64_t& value) { this->px_offset_x = value; }

        const int64_t& get_px_offset_y() const { return px_offset_y; }
        int64_t& get_mutable_px_offset_y() { return px_offset_y; }
        void set_px_offset_y(const int64_t& value) { this->px_offset_y = value; }

        const bool& get_visible() const { return visible; }
        bool& get_mutable_visible() { return visible; }
        void set_visible(const bool& value) { this->visible = value; }

        const std::vector<nlohmann::json>& get_optional_rules() const { return optional_rules; }
        std::vector<nlohmann::json>& get_mutable_optional_rules() { return optional_rules; }
        void set_optional_rules(const std::vector<nlohmann::json>& value) { this->optional_rules = value; }

        const std::vector<int64_t>& get_int_grid_csv() const { return int_grid_csv; }
        std::vector<int64_t>& get_mutable_int_grid_csv() { return int_grid_csv; }
        void set_int_grid_csv(const std::vector<int64_t>& value) { this->int_grid_csv = value; }

        const std::vector<AutoLayerTile>& get_auto_layer_tiles() const { return auto_layer_tiles; }
        std::vector<AutoLayerTile>& get_mutable_auto_layer_tiles() { return auto_layer_tiles; }
        void set_auto_layer_tiles(const std::vector<AutoLayerTile>& value) { this->auto_layer_tiles = value; }

        const int64_t& get_seed() const { return seed; }
        int64_t& get_mutable_seed() { return seed; }
        void set_seed(const int64_t& value) { this->seed = value; }

        const nlohmann::json& get_override_tileset_uid() const { return override_tileset_uid; }
        nlohmann::json& get_mutable_override_tileset_uid() { return override_tileset_uid; }
        void set_override_tileset_uid(const nlohmann::json& value) { this->override_tileset_uid = value; }

        const std::vector<nlohmann::json>& get_grid_tiles() const { return grid_tiles; }
        std::vector<nlohmann::json>& get_mutable_grid_tiles() { return grid_tiles; }
        void set_grid_tiles(const std::vector<nlohmann::json>& value) { this->grid_tiles = value; }

        const std::vector<nlohmann::json>& get_entity_instances() const { return entity_instances; }
        std::vector<nlohmann::json>& get_mutable_entity_instances() { return entity_instances; }
        void set_entity_instances(const std::vector<nlohmann::json>& value) { this->entity_instances = value; }
    };

    class Level {
    public:
        Level() = default;
        virtual ~Level() = default;

    private:
        std::string identifier;
        std::string iid;
        int64_t uid;
        int64_t world_x;
        int64_t world_y;
        int64_t world_depth;
        int64_t px_wid;
        int64_t px_hei;
        std::string bg_color;
        nlohmann::json level_bg_color;
        bool use_auto_identifier;
        nlohmann::json bg_rel_path;
        nlohmann::json level_bg_pos;
        double bg_pivot_x;
        double bg_pivot_y;
        std::string smart_color;
        nlohmann::json bg_pos;
        nlohmann::json external_rel_path;
        std::vector<nlohmann::json> field_instances;
        std::vector<LayerInstance> layer_instances;
        std::vector<nlohmann::json> neighbours;

    public:
        const std::string& get_identifier() const { return identifier; }
        std::string& get_mutable_identifier() { return identifier; }
        void set_identifier(const std::string& value) { this->identifier = value; }

        const std::string& get_iid() const { return iid; }
        std::string& get_mutable_iid() { return iid; }
        void set_iid(const std::string& value) { this->iid = value; }

        const int64_t& get_uid() const { return uid; }
        int64_t& get_mutable_uid() { return uid; }
        void set_uid(const int64_t& value) { this->uid = value; }

        const int64_t& get_world_x() const { return world_x; }
        int64_t& get_mutable_world_x() { return world_x; }
        void set_world_x(const int64_t& value) { this->world_x = value; }

        const int64_t& get_world_y() const { return world_y; }
        int64_t& get_mutable_world_y() { return world_y; }
        void set_world_y(const int64_t& value) { this->world_y = value; }

        const int64_t& get_world_depth() const { return world_depth; }
        int64_t& get_mutable_world_depth() { return world_depth; }
        void set_world_depth(const int64_t& value) { this->world_depth = value; }

        const int64_t& get_px_wid() const { return px_wid; }
        int64_t& get_mutable_px_wid() { return px_wid; }
        void set_px_wid(const int64_t& value) { this->px_wid = value; }

        const int64_t& get_px_hei() const { return px_hei; }
        int64_t& get_mutable_px_hei() { return px_hei; }
        void set_px_hei(const int64_t& value) { this->px_hei = value; }

        const std::string& get_bg_color() const { return bg_color; }
        std::string& get_mutable_bg_color() { return bg_color; }
        void set_bg_color(const std::string& value) { this->bg_color = value; }

        const nlohmann::json& get_level_bg_color() const { return level_bg_color; }
        nlohmann::json& get_mutable_level_bg_color() { return level_bg_color; }
        void set_level_bg_color(const nlohmann::json& value) { this->level_bg_color = value; }

        const bool& get_use_auto_identifier() const { return use_auto_identifier; }
        bool& get_mutable_use_auto_identifier() { return use_auto_identifier; }
        void set_use_auto_identifier(const bool& value) { this->use_auto_identifier = value; }

        const nlohmann::json& get_bg_rel_path() const { return bg_rel_path; }
        nlohmann::json& get_mutable_bg_rel_path() { return bg_rel_path; }
        void set_bg_rel_path(const nlohmann::json& value) { this->bg_rel_path = value; }

        const nlohmann::json& get_level_bg_pos() const { return level_bg_pos; }
        nlohmann::json& get_mutable_level_bg_pos() { return level_bg_pos; }
        void set_level_bg_pos(const nlohmann::json& value) { this->level_bg_pos = value; }

        const double& get_bg_pivot_x() const { return bg_pivot_x; }
        double& get_mutable_bg_pivot_x() { return bg_pivot_x; }
        void set_bg_pivot_x(const double& value) { this->bg_pivot_x = value; }

        const double& get_bg_pivot_y() const { return bg_pivot_y; }
        double& get_mutable_bg_pivot_y() { return bg_pivot_y; }
        void set_bg_pivot_y(const double& value) { this->bg_pivot_y = value; }

        const std::string& get_smart_color() const { return smart_color; }
        std::string& get_mutable_smart_color() { return smart_color; }
        void set_smart_color(const std::string& value) { this->smart_color = value; }

        const nlohmann::json& get_bg_pos() const { return bg_pos; }
        nlohmann::json& get_mutable_bg_pos() { return bg_pos; }
        void set_bg_pos(const nlohmann::json& value) { this->bg_pos = value; }

        const nlohmann::json& get_external_rel_path() const { return external_rel_path; }
        nlohmann::json& get_mutable_external_rel_path() { return external_rel_path; }
        void set_external_rel_path(const nlohmann::json& value) { this->external_rel_path = value; }

        const std::vector<nlohmann::json>& get_field_instances() const { return field_instances; }
        std::vector<nlohmann::json>& get_mutable_field_instances() { return field_instances; }
        void set_field_instances(const std::vector<nlohmann::json>& value) { this->field_instances = value; }

        const std::vector<LayerInstance>& get_layer_instances() const { return layer_instances; }
        std::vector<LayerInstance>& get_mutable_layer_instances() { return layer_instances; }
        void set_layer_instances(const std::vector<LayerInstance>& value) { this->layer_instances = value; }

        const std::vector<nlohmann::json>& get_neighbours() const { return neighbours; }
        std::vector<nlohmann::json>& get_mutable_neighbours() { return neighbours; }
        void set_neighbours(const std::vector<nlohmann::json>& value) { this->neighbours = value; }
    };

    class LdtkJson {
    public:
        LdtkJson() = default;
        virtual ~LdtkJson() = default;

    private:
        Header header;
        std::string iid;
        std::string json_version;
        int64_t app_build_id;
        int64_t next_uid;
        std::string identifier_style;
        std::vector<nlohmann::json> toc;
        std::string world_layout;
        int64_t world_grid_width;
        int64_t world_grid_height;
        int64_t default_level_width;
        int64_t default_level_height;
        int64_t default_pivot_x;
        int64_t default_pivot_y;
        int64_t default_grid_size;
        int64_t default_entity_width;
        int64_t default_entity_height;
        std::string bg_color;
        std::string default_level_bg_color;
        bool minify_json;
        bool external_levels;
        bool export_tiled;
        bool simplified_export;
        ImageExportMode image_export_mode;
        bool export_level_bg;
        nlohmann::json png_file_pattern;
        bool backup_on_save;
        int64_t backup_limit;
        nlohmann::json backup_rel_path;
        std::string level_name_pattern;
        std::string tutorial_desc;
        std::vector<nlohmann::json> custom_commands;
        std::vector<std::string> flags;
        Defs defs;
        std::vector<Level> levels;
        std::vector<nlohmann::json> worlds;
        std::string dummy_world_iid;

    public:
        const Header& get_header() const { return header; }
        Header& get_mutable_header() { return header; }
        void set_header(const Header& value) { this->header = value; }

        const std::string& get_iid() const { return iid; }
        std::string& get_mutable_iid() { return iid; }
        void set_iid(const std::string& value) { this->iid = value; }

        const std::string& get_json_version() const { return json_version; }
        std::string& get_mutable_json_version() { return json_version; }
        void set_json_version(const std::string& value) { this->json_version = value; }

        const int64_t& get_app_build_id() const { return app_build_id; }
        int64_t& get_mutable_app_build_id() { return app_build_id; }
        void set_app_build_id(const int64_t& value) { this->app_build_id = value; }

        const int64_t& get_next_uid() const { return next_uid; }
        int64_t& get_mutable_next_uid() { return next_uid; }
        void set_next_uid(const int64_t& value) { this->next_uid = value; }

        const std::string& get_identifier_style() const { return identifier_style; }
        std::string& get_mutable_identifier_style() { return identifier_style; }
        void set_identifier_style(const std::string& value) { this->identifier_style = value; }

        const std::vector<nlohmann::json>& get_toc() const { return toc; }
        std::vector<nlohmann::json>& get_mutable_toc() { return toc; }
        void set_toc(const std::vector<nlohmann::json>& value) { this->toc = value; }

        const std::string& get_world_layout() const { return world_layout; }
        std::string& get_mutable_world_layout() { return world_layout; }
        void set_world_layout(const std::string& value) { this->world_layout = value; }

        const int64_t& get_world_grid_width() const { return world_grid_width; }
        int64_t& get_mutable_world_grid_width() { return world_grid_width; }
        void set_world_grid_width(const int64_t& value) { this->world_grid_width = value; }

        const int64_t& get_world_grid_height() const { return world_grid_height; }
        int64_t& get_mutable_world_grid_height() { return world_grid_height; }
        void set_world_grid_height(const int64_t& value) { this->world_grid_height = value; }

        const int64_t& get_default_level_width() const { return default_level_width; }
        int64_t& get_mutable_default_level_width() { return default_level_width; }
        void set_default_level_width(const int64_t& value) { this->default_level_width = value; }

        const int64_t& get_default_level_height() const { return default_level_height; }
        int64_t& get_mutable_default_level_height() { return default_level_height; }
        void set_default_level_height(const int64_t& value) { this->default_level_height = value; }

        const int64_t& get_default_pivot_x() const { return default_pivot_x; }
        int64_t& get_mutable_default_pivot_x() { return default_pivot_x; }
        void set_default_pivot_x(const int64_t& value) { this->default_pivot_x = value; }

        const int64_t& get_default_pivot_y() const { return default_pivot_y; }
        int64_t& get_mutable_default_pivot_y() { return default_pivot_y; }
        void set_default_pivot_y(const int64_t& value) { this->default_pivot_y = value; }

        const int64_t& get_default_grid_size() const { return default_grid_size; }
        int64_t& get_mutable_default_grid_size() { return default_grid_size; }
        void set_default_grid_size(const int64_t& value) { this->default_grid_size = value; }

        const int64_t& get_default_entity_width() const { return default_entity_width; }
        int64_t& get_mutable_default_entity_width() { return default_entity_width; }
        void set_default_entity_width(const int64_t& value) { this->default_entity_width = value; }

        const int64_t& get_default_entity_height() const { return default_entity_height; }
        int64_t& get_mutable_default_entity_height() { return default_entity_height; }
        void set_default_entity_height(const int64_t& value) { this->default_entity_height = value; }

        const std::string& get_bg_color() const { return bg_color; }
        std::string& get_mutable_bg_color() { return bg_color; }
        void set_bg_color(const std::string& value) { this->bg_color = value; }

        const std::string& get_default_level_bg_color() const { return default_level_bg_color; }
        std::string& get_mutable_default_level_bg_color() { return default_level_bg_color; }
        void set_default_level_bg_color(const std::string& value) { this->default_level_bg_color = value; }

        const bool& get_minify_json() const { return minify_json; }
        bool& get_mutable_minify_json() { return minify_json; }
        void set_minify_json(const bool& value) { this->minify_json = value; }

        const bool& get_external_levels() const { return external_levels; }
        bool& get_mutable_external_levels() { return external_levels; }
        void set_external_levels(const bool& value) { this->external_levels = value; }

        const bool& get_export_tiled() const { return export_tiled; }
        bool& get_mutable_export_tiled() { return export_tiled; }
        void set_export_tiled(const bool& value) { this->export_tiled = value; }

        const bool& get_simplified_export() const { return simplified_export; }
        bool& get_mutable_simplified_export() { return simplified_export; }
        void set_simplified_export(const bool& value) { this->simplified_export = value; }

        const ImageExportMode& get_image_export_mode() const { return image_export_mode; }
        ImageExportMode& get_mutable_image_export_mode() { return image_export_mode; }
        void set_image_export_mode(const ImageExportMode& value) { this->image_export_mode = value; }

        const bool& get_export_level_bg() const { return export_level_bg; }
        bool& get_mutable_export_level_bg() { return export_level_bg; }
        void set_export_level_bg(const bool& value) { this->export_level_bg = value; }

        const nlohmann::json& get_png_file_pattern() const { return png_file_pattern; }
        nlohmann::json& get_mutable_png_file_pattern() { return png_file_pattern; }
        void set_png_file_pattern(const nlohmann::json& value) { this->png_file_pattern = value; }

        const bool& get_backup_on_save() const { return backup_on_save; }
        bool& get_mutable_backup_on_save() { return backup_on_save; }
        void set_backup_on_save(const bool& value) { this->backup_on_save = value; }

        const int64_t& get_backup_limit() const { return backup_limit; }
        int64_t& get_mutable_backup_limit() { return backup_limit; }
        void set_backup_limit(const int64_t& value) { this->backup_limit = value; }

        const nlohmann::json& get_backup_rel_path() const { return backup_rel_path; }
        nlohmann::json& get_mutable_backup_rel_path() { return backup_rel_path; }
        void set_backup_rel_path(const nlohmann::json& value) { this->backup_rel_path = value; }

        const std::string& get_level_name_pattern() const { return level_name_pattern; }
        std::string& get_mutable_level_name_pattern() { return level_name_pattern; }
        void set_level_name_pattern(const std::string& value) { this->level_name_pattern = value; }

        const std::string& get_tutorial_desc() const { return tutorial_desc; }
        std::string& get_mutable_tutorial_desc() { return tutorial_desc; }
        void set_tutorial_desc(const std::string& value) { this->tutorial_desc = value; }

        const std::vector<nlohmann::json>& get_custom_commands() const { return custom_commands; }
        std::vector<nlohmann::json>& get_mutable_custom_commands() { return custom_commands; }
        void set_custom_commands(const std::vector<nlohmann::json>& value) { this->custom_commands = value; }

        const std::vector<std::string>& get_flags() const { return flags; }
        std::vector<std::string>& get_mutable_flags() { return flags; }
        void set_flags(const std::vector<std::string>& value) { this->flags = value; }

        const Defs& get_defs() const { return defs; }
        Defs& get_mutable_defs() { return defs; }
        void set_defs(const Defs& value) { this->defs = value; }

        const std::vector<Level>& get_levels() const { return levels; }
        std::vector<Level>& get_mutable_levels() { return levels; }
        void set_levels(const std::vector<Level>& value) { this->levels = value; }

        const std::vector<nlohmann::json>& get_worlds() const { return worlds; }
        std::vector<nlohmann::json>& get_mutable_worlds() { return worlds; }
        void set_worlds(const std::vector<nlohmann::json>& value) { this->worlds = value; }

        const std::string& get_dummy_world_iid() const { return dummy_world_iid; }
        std::string& get_mutable_dummy_world_iid() { return dummy_world_iid; }
        void set_dummy_world_iid(const std::string& value) { this->dummy_world_iid = value; }
    };
}

namespace quicktype {
    void from_json(const json& j, Icon& x);
    void to_json(json& j, const Icon& x);

    void from_json(const json& j, Rule& x);
    void to_json(json& j, const Rule& x);

    void from_json(const json& j, AutoRuleGroup& x);
    void to_json(json& j, const AutoRuleGroup& x);

    void from_json(const json& j, IntGridValue& x);
    void to_json(json& j, const IntGridValue& x);

    void from_json(const json& j, Layer& x);
    void to_json(json& j, const Layer& x);

    void from_json(const json& j, CachedPixelData& x);
    void to_json(json& j, const CachedPixelData& x);

    void from_json(const json& j, SavedSelection& x);
    void to_json(json& j, const SavedSelection& x);

    void from_json(const json& j, Tileset& x);
    void to_json(json& j, const Tileset& x);

    void from_json(const json& j, Defs& x);
    void to_json(json& j, const Defs& x);

    void from_json(const json& j, Header& x);
    void to_json(json& j, const Header& x);

    void from_json(const json& j, AutoLayerTile& x);
    void to_json(json& j, const AutoLayerTile& x);

    void from_json(const json& j, LayerInstance& x);
    void to_json(json& j, const LayerInstance& x);

    void from_json(const json& j, Level& x);
    void to_json(json& j, const Level& x);

    void from_json(const json& j, LdtkJson& x);
    void to_json(json& j, const LdtkJson& x);

    void from_json(const json& j, ImageExportMode& x);
    void to_json(json& j, const ImageExportMode& x);

    void from_json(const json& j, TileMode& x);
    void to_json(json& j, const TileMode& x);

    void from_json(const json& j, Mode& x);
    void to_json(json& j, const Mode& x);

    inline void from_json(const json& j, Icon& x) {
        x.set_tileset_uid(j.at("tilesetUid").get<int64_t>());
        x.set_x(j.at("x").get<int64_t>());
        x.set_y(j.at("y").get<int64_t>());
        x.set_w(j.at("w").get<int64_t>());
        x.set_h(j.at("h").get<int64_t>());
    }

    inline void to_json(json& j, const Icon& x) {
        j = json::object();
        j["tilesetUid"] = x.get_tileset_uid();
        j["x"] = x.get_x();
        j["y"] = x.get_y();
        j["w"] = x.get_w();
        j["h"] = x.get_h();
    }

    inline void from_json(const json& j, Rule& x) {
        x.set_uid(j.at("uid").get<int64_t>());
        x.set_active(j.at("active").get<bool>());
        x.set_size(j.at("size").get<int64_t>());
        x.set_tile_rects_ids(j.at("tileRectsIds").get<std::vector<std::vector<int64_t>>>());
        x.set_alpha(j.at("alpha").get<int64_t>());
        x.set_chance(j.at("chance").get<double>());
        x.set_break_on_match(j.at("breakOnMatch").get<bool>());
        x.set_pattern(j.at("pattern").get<std::vector<int64_t>>());
        x.set_flip_x(j.at("flipX").get<bool>());
        x.set_flip_y(j.at("flipY").get<bool>());
        x.set_x_modulo(j.at("xModulo").get<int64_t>());
        x.set_y_modulo(j.at("yModulo").get<int64_t>());
        x.set_x_offset(j.at("xOffset").get<int64_t>());
        x.set_y_offset(j.at("yOffset").get<int64_t>());
        x.set_tile_x_offset(j.at("tileXOffset").get<int64_t>());
        x.set_tile_y_offset(j.at("tileYOffset").get<int64_t>());
        x.set_tile_random_x_min(j.at("tileRandomXMin").get<int64_t>());
        x.set_tile_random_x_max(j.at("tileRandomXMax").get<int64_t>());
        x.set_tile_random_y_min(j.at("tileRandomYMin").get<int64_t>());
        x.set_tile_random_y_max(j.at("tileRandomYMax").get<int64_t>());
        x.set_checker(j.at("checker").get<ImageExportMode>());
        x.set_tile_mode(j.at("tileMode").get<TileMode>());
        x.set_pivot_x(j.at("pivotX").get<int64_t>());
        x.set_pivot_y(j.at("pivotY").get<int64_t>());
        x.set_out_of_bounds_value(get_untyped(j, "outOfBoundsValue"));
        x.set_invalidated(j.at("invalidated").get<bool>());
        x.set_perlin_active(j.at("perlinActive").get<bool>());
        x.set_perlin_seed(j.at("perlinSeed").get<int64_t>());
        x.set_perlin_scale(j.at("perlinScale").get<double>());
        x.set_perlin_octaves(j.at("perlinOctaves").get<int64_t>());
    }

    inline void to_json(json& j, const Rule& x) {
        j = json::object();
        j["uid"] = x.get_uid();
        j["active"] = x.get_active();
        j["size"] = x.get_size();
        j["tileRectsIds"] = x.get_tile_rects_ids();
        j["alpha"] = x.get_alpha();
        j["chance"] = x.get_chance();
        j["breakOnMatch"] = x.get_break_on_match();
        j["pattern"] = x.get_pattern();
        j["flipX"] = x.get_flip_x();
        j["flipY"] = x.get_flip_y();
        j["xModulo"] = x.get_x_modulo();
        j["yModulo"] = x.get_y_modulo();
        j["xOffset"] = x.get_x_offset();
        j["yOffset"] = x.get_y_offset();
        j["tileXOffset"] = x.get_tile_x_offset();
        j["tileYOffset"] = x.get_tile_y_offset();
        j["tileRandomXMin"] = x.get_tile_random_x_min();
        j["tileRandomXMax"] = x.get_tile_random_x_max();
        j["tileRandomYMin"] = x.get_tile_random_y_min();
        j["tileRandomYMax"] = x.get_tile_random_y_max();
        j["checker"] = x.get_checker();
        j["tileMode"] = x.get_tile_mode();
        j["pivotX"] = x.get_pivot_x();
        j["pivotY"] = x.get_pivot_y();
        j["outOfBoundsValue"] = x.get_out_of_bounds_value();
        j["invalidated"] = x.get_invalidated();
        j["perlinActive"] = x.get_perlin_active();
        j["perlinSeed"] = x.get_perlin_seed();
        j["perlinScale"] = x.get_perlin_scale();
        j["perlinOctaves"] = x.get_perlin_octaves();
    }

    inline void from_json(const json& j, AutoRuleGroup& x) {
        x.set_uid(j.at("uid").get<int64_t>());
        x.set_name(j.at("name").get<std::string>());
        x.set_color(get_stack_optional<std::string>(j, "color"));
        x.set_icon(j.at("icon").get<Icon>());
        x.set_active(j.at("active").get<bool>());
        x.set_is_optional(j.at("isOptional").get<bool>());
        x.set_rules(j.at("rules").get<std::vector<Rule>>());
        x.set_uses_wizard(j.at("usesWizard").get<bool>());
        x.set_required_biome_values(j.at("requiredBiomeValues").get<std::vector<nlohmann::json>>());
        x.set_biome_requirement_mode(j.at("biomeRequirementMode").get<int64_t>());
    }

    inline void to_json(json& j, const AutoRuleGroup& x) {
        j = json::object();
        j["uid"] = x.get_uid();
        j["name"] = x.get_name();
        j["color"] = x.get_color();
        j["icon"] = x.get_icon();
        j["active"] = x.get_active();
        j["isOptional"] = x.get_is_optional();
        j["rules"] = x.get_rules();
        j["usesWizard"] = x.get_uses_wizard();
        j["requiredBiomeValues"] = x.get_required_biome_values();
        j["biomeRequirementMode"] = x.get_biome_requirement_mode();
    }

    inline void from_json(const json& j, IntGridValue& x) {
        x.set_value(j.at("value").get<int64_t>());
        x.set_identifier(j.at("identifier").get<std::string>());
        x.set_color(j.at("color").get<std::string>());
        x.set_tile(j.at("tile").get<Icon>());
        x.set_group_uid(j.at("groupUid").get<int64_t>());
    }

    inline void to_json(json& j, const IntGridValue& x) {
        j = json::object();
        j["value"] = x.get_value();
        j["identifier"] = x.get_identifier();
        j["color"] = x.get_color();
        j["tile"] = x.get_tile();
        j["groupUid"] = x.get_group_uid();
    }

    inline void from_json(const json& j, Layer& x) {
        x.set_type(j.at("__type").get<std::string>());
        x.set_identifier(j.at("identifier").get<std::string>());
        x.set_layer_type(j.at("type").get<std::string>());
        x.set_uid(j.at("uid").get<int64_t>());
        x.set_doc(get_untyped(j, "doc"));
        x.set_ui_color(get_untyped(j, "uiColor"));
        x.set_grid_size(j.at("gridSize").get<int64_t>());
        x.set_guide_grid_wid(j.at("guideGridWid").get<int64_t>());
        x.set_guide_grid_hei(j.at("guideGridHei").get<int64_t>());
        x.set_display_opacity(j.at("displayOpacity").get<int64_t>());
        x.set_inactive_opacity(j.at("inactiveOpacity").get<int64_t>());
        x.set_hide_in_list(j.at("hideInList").get<bool>());
        x.set_hide_fields_when_inactive(j.at("hideFieldsWhenInactive").get<bool>());
        x.set_can_select_when_inactive(j.at("canSelectWhenInactive").get<bool>());
        x.set_render_in_world_view(j.at("renderInWorldView").get<bool>());
        x.set_px_offset_x(j.at("pxOffsetX").get<int64_t>());
        x.set_px_offset_y(j.at("pxOffsetY").get<int64_t>());
        x.set_parallax_factor_x(j.at("parallaxFactorX").get<int64_t>());
        x.set_parallax_factor_y(j.at("parallaxFactorY").get<int64_t>());
        x.set_parallax_scaling(j.at("parallaxScaling").get<bool>());
        x.set_required_tags(j.at("requiredTags").get<std::vector<nlohmann::json>>());
        x.set_excluded_tags(j.at("excludedTags").get<std::vector<nlohmann::json>>());
        x.set_auto_tiles_killed_by_other_layer_uid(get_untyped(j, "autoTilesKilledByOtherLayerUid"));
        x.set_ui_filter_tags(j.at("uiFilterTags").get<std::vector<nlohmann::json>>());
        x.set_use_async_render(j.at("useAsyncRender").get<bool>());
        x.set_int_grid_values(j.at("intGridValues").get<std::vector<IntGridValue>>());
        x.set_int_grid_values_groups(j.at("intGridValuesGroups").get<std::vector<nlohmann::json>>());
        x.set_auto_rule_groups(j.at("autoRuleGroups").get<std::vector<AutoRuleGroup>>());
        x.set_auto_source_layer_def_uid(get_untyped(j, "autoSourceLayerDefUid"));
        x.set_tileset_def_uid(j.at("tilesetDefUid").get<int64_t>());
        x.set_tile_pivot_x(j.at("tilePivotX").get<int64_t>());
        x.set_tile_pivot_y(j.at("tilePivotY").get<int64_t>());
        x.set_biome_field_uid(get_untyped(j, "biomeFieldUid"));
    }

    inline void to_json(json& j, const Layer& x) {
        j = json::object();
        j["__type"] = x.get_type();
        j["identifier"] = x.get_identifier();
        j["type"] = x.get_layer_type();
        j["uid"] = x.get_uid();
        j["doc"] = x.get_doc();
        j["uiColor"] = x.get_ui_color();
        j["gridSize"] = x.get_grid_size();
        j["guideGridWid"] = x.get_guide_grid_wid();
        j["guideGridHei"] = x.get_guide_grid_hei();
        j["displayOpacity"] = x.get_display_opacity();
        j["inactiveOpacity"] = x.get_inactive_opacity();
        j["hideInList"] = x.get_hide_in_list();
        j["hideFieldsWhenInactive"] = x.get_hide_fields_when_inactive();
        j["canSelectWhenInactive"] = x.get_can_select_when_inactive();
        j["renderInWorldView"] = x.get_render_in_world_view();
        j["pxOffsetX"] = x.get_px_offset_x();
        j["pxOffsetY"] = x.get_px_offset_y();
        j["parallaxFactorX"] = x.get_parallax_factor_x();
        j["parallaxFactorY"] = x.get_parallax_factor_y();
        j["parallaxScaling"] = x.get_parallax_scaling();
        j["requiredTags"] = x.get_required_tags();
        j["excludedTags"] = x.get_excluded_tags();
        j["autoTilesKilledByOtherLayerUid"] = x.get_auto_tiles_killed_by_other_layer_uid();
        j["uiFilterTags"] = x.get_ui_filter_tags();
        j["useAsyncRender"] = x.get_use_async_render();
        j["intGridValues"] = x.get_int_grid_values();
        j["intGridValuesGroups"] = x.get_int_grid_values_groups();
        j["autoRuleGroups"] = x.get_auto_rule_groups();
        j["autoSourceLayerDefUid"] = x.get_auto_source_layer_def_uid();
        j["tilesetDefUid"] = x.get_tileset_def_uid();
        j["tilePivotX"] = x.get_tile_pivot_x();
        j["tilePivotY"] = x.get_tile_pivot_y();
        j["biomeFieldUid"] = x.get_biome_field_uid();
    }

    inline void from_json(const json& j, CachedPixelData& x) {
        x.set_opaque_tiles(j.at("opaqueTiles").get<std::string>());
        x.set_average_colors(j.at("averageColors").get<std::string>());
    }

    inline void to_json(json& j, const CachedPixelData& x) {
        j = json::object();
        j["opaqueTiles"] = x.get_opaque_tiles();
        j["averageColors"] = x.get_average_colors();
    }

    inline void from_json(const json& j, SavedSelection& x) {
        x.set_ids(j.at("ids").get<std::vector<int64_t>>());
        x.set_mode(j.at("mode").get<Mode>());
    }

    inline void to_json(json& j, const SavedSelection& x) {
        j = json::object();
        j["ids"] = x.get_ids();
        j["mode"] = x.get_mode();
    }

    inline void from_json(const json& j, Tileset& x) {
        x.set_c_wid(j.at("__cWid").get<int64_t>());
        x.set_c_hei(j.at("__cHei").get<int64_t>());
        x.set_identifier(j.at("identifier").get<std::string>());
        x.set_uid(j.at("uid").get<int64_t>());
        x.set_rel_path(j.at("relPath").get<std::string>());
        x.set_embed_atlas(get_untyped(j, "embedAtlas"));
        x.set_px_wid(j.at("pxWid").get<int64_t>());
        x.set_px_hei(j.at("pxHei").get<int64_t>());
        x.set_tile_grid_size(j.at("tileGridSize").get<int64_t>());
        x.set_spacing(j.at("spacing").get<int64_t>());
        x.set_padding(j.at("padding").get<int64_t>());
        x.set_tags(j.at("tags").get<std::vector<nlohmann::json>>());
        x.set_tags_source_enum_uid(get_untyped(j, "tagsSourceEnumUid"));
        x.set_enum_tags(j.at("enumTags").get<std::vector<nlohmann::json>>());
        x.set_custom_data(j.at("customData").get<std::vector<nlohmann::json>>());
        x.set_saved_selections(j.at("savedSelections").get<std::vector<SavedSelection>>());
        x.set_cached_pixel_data(j.at("cachedPixelData").get<CachedPixelData>());
    }

    inline void to_json(json& j, const Tileset& x) {
        j = json::object();
        j["__cWid"] = x.get_c_wid();
        j["__cHei"] = x.get_c_hei();
        j["identifier"] = x.get_identifier();
        j["uid"] = x.get_uid();
        j["relPath"] = x.get_rel_path();
        j["embedAtlas"] = x.get_embed_atlas();
        j["pxWid"] = x.get_px_wid();
        j["pxHei"] = x.get_px_hei();
        j["tileGridSize"] = x.get_tile_grid_size();
        j["spacing"] = x.get_spacing();
        j["padding"] = x.get_padding();
        j["tags"] = x.get_tags();
        j["tagsSourceEnumUid"] = x.get_tags_source_enum_uid();
        j["enumTags"] = x.get_enum_tags();
        j["customData"] = x.get_custom_data();
        j["savedSelections"] = x.get_saved_selections();
        j["cachedPixelData"] = x.get_cached_pixel_data();
    }

    inline void from_json(const json& j, Defs& x) {
        x.set_layers(j.at("layers").get<std::vector<Layer>>());
        x.set_entities(j.at("entities").get<std::vector<nlohmann::json>>());
        x.set_tilesets(j.at("tilesets").get<std::vector<Tileset>>());
        x.set_enums(j.at("enums").get<std::vector<nlohmann::json>>());
        x.set_external_enums(j.at("externalEnums").get<std::vector<nlohmann::json>>());
        x.set_level_fields(j.at("levelFields").get<std::vector<nlohmann::json>>());
    }

    inline void to_json(json& j, const Defs& x) {
        j = json::object();
        j["layers"] = x.get_layers();
        j["entities"] = x.get_entities();
        j["tilesets"] = x.get_tilesets();
        j["enums"] = x.get_enums();
        j["externalEnums"] = x.get_external_enums();
        j["levelFields"] = x.get_level_fields();
    }

    inline void from_json(const json& j, Header& x) {
        x.set_file_type(j.at("fileType").get<std::string>());
        x.set_app(j.at("app").get<std::string>());
        x.set_doc(j.at("doc").get<std::string>());
        x.set_schema(j.at("schema").get<std::string>());
        x.set_app_author(j.at("appAuthor").get<std::string>());
        x.set_app_version(j.at("appVersion").get<std::string>());
        x.set_url(j.at("url").get<std::string>());
    }

    inline void to_json(json& j, const Header& x) {
        j = json::object();
        j["fileType"] = x.get_file_type();
        j["app"] = x.get_app();
        j["doc"] = x.get_doc();
        j["schema"] = x.get_schema();
        j["appAuthor"] = x.get_app_author();
        j["appVersion"] = x.get_app_version();
        j["url"] = x.get_url();
    }

    inline void from_json(const json& j, AutoLayerTile& x) {
        x.set_px(j.at("px").get<std::vector<int64_t>>());
        x.set_src(j.at("src").get<std::vector<int64_t>>());
        x.set_f(j.at("f").get<int64_t>());
        x.set_t(j.at("t").get<int64_t>());
        x.set_d(j.at("d").get<std::vector<int64_t>>());
        x.set_a(j.at("a").get<int64_t>());
    }

    inline void to_json(json& j, const AutoLayerTile& x) {
        j = json::object();
        j["px"] = x.get_px();
        j["src"] = x.get_src();
        j["f"] = x.get_f();
        j["t"] = x.get_t();
        j["d"] = x.get_d();
        j["a"] = x.get_a();
    }

    inline void from_json(const json& j, LayerInstance& x) {
        x.set_identifier(j.at("__identifier").get<std::string>());
        x.set_type(j.at("__type").get<std::string>());
        x.set_c_wid(j.at("__cWid").get<int64_t>());
        x.set_c_hei(j.at("__cHei").get<int64_t>());
        x.set_grid_size(j.at("__gridSize").get<int64_t>());
        x.set_opacity(j.at("__opacity").get<int64_t>());
        x.set_px_total_offset_x(j.at("__pxTotalOffsetX").get<int64_t>());
        x.set_px_total_offset_y(j.at("__pxTotalOffsetY").get<int64_t>());
        x.set_tileset_def_uid(j.at("__tilesetDefUid").get<int64_t>());
        x.set_tileset_rel_path(j.at("__tilesetRelPath").get<std::string>());
        x.set_iid(j.at("iid").get<std::string>());
        x.set_level_id(j.at("levelId").get<int64_t>());
        x.set_layer_def_uid(j.at("layerDefUid").get<int64_t>());
        x.set_px_offset_x(j.at("pxOffsetX").get<int64_t>());
        x.set_px_offset_y(j.at("pxOffsetY").get<int64_t>());
        x.set_visible(j.at("visible").get<bool>());
        x.set_optional_rules(j.at("optionalRules").get<std::vector<nlohmann::json>>());
        x.set_int_grid_csv(j.at("intGridCsv").get<std::vector<int64_t>>());
        x.set_auto_layer_tiles(j.at("autoLayerTiles").get<std::vector<AutoLayerTile>>());
        x.set_seed(j.at("seed").get<int64_t>());
        x.set_override_tileset_uid(get_untyped(j, "overrideTilesetUid"));
        x.set_grid_tiles(j.at("gridTiles").get<std::vector<nlohmann::json>>());
        x.set_entity_instances(j.at("entityInstances").get<std::vector<nlohmann::json>>());
    }

    inline void to_json(json& j, const LayerInstance& x) {
        j = json::object();
        j["__identifier"] = x.get_identifier();
        j["__type"] = x.get_type();
        j["__cWid"] = x.get_c_wid();
        j["__cHei"] = x.get_c_hei();
        j["__gridSize"] = x.get_grid_size();
        j["__opacity"] = x.get_opacity();
        j["__pxTotalOffsetX"] = x.get_px_total_offset_x();
        j["__pxTotalOffsetY"] = x.get_px_total_offset_y();
        j["__tilesetDefUid"] = x.get_tileset_def_uid();
        j["__tilesetRelPath"] = x.get_tileset_rel_path();
        j["iid"] = x.get_iid();
        j["levelId"] = x.get_level_id();
        j["layerDefUid"] = x.get_layer_def_uid();
        j["pxOffsetX"] = x.get_px_offset_x();
        j["pxOffsetY"] = x.get_px_offset_y();
        j["visible"] = x.get_visible();
        j["optionalRules"] = x.get_optional_rules();
        j["intGridCsv"] = x.get_int_grid_csv();
        j["autoLayerTiles"] = x.get_auto_layer_tiles();
        j["seed"] = x.get_seed();
        j["overrideTilesetUid"] = x.get_override_tileset_uid();
        j["gridTiles"] = x.get_grid_tiles();
        j["entityInstances"] = x.get_entity_instances();
    }

    inline void from_json(const json& j, Level& x) {
        x.set_identifier(j.at("identifier").get<std::string>());
        x.set_iid(j.at("iid").get<std::string>());
        x.set_uid(j.at("uid").get<int64_t>());
        x.set_world_x(j.at("worldX").get<int64_t>());
        x.set_world_y(j.at("worldY").get<int64_t>());
        x.set_world_depth(j.at("worldDepth").get<int64_t>());
        x.set_px_wid(j.at("pxWid").get<int64_t>());
        x.set_px_hei(j.at("pxHei").get<int64_t>());
        x.set_bg_color(j.at("__bgColor").get<std::string>());
        x.set_level_bg_color(get_untyped(j, "bgColor"));
        x.set_use_auto_identifier(j.at("useAutoIdentifier").get<bool>());
        x.set_bg_rel_path(get_untyped(j, "bgRelPath"));
        x.set_level_bg_pos(get_untyped(j, "bgPos"));
        x.set_bg_pivot_x(j.at("bgPivotX").get<double>());
        x.set_bg_pivot_y(j.at("bgPivotY").get<double>());
        x.set_smart_color(j.at("__smartColor").get<std::string>());
        x.set_bg_pos(get_untyped(j, "__bgPos"));
        x.set_external_rel_path(get_untyped(j, "externalRelPath"));
        x.set_field_instances(j.at("fieldInstances").get<std::vector<nlohmann::json>>());
        x.set_layer_instances(j.at("layerInstances").get<std::vector<LayerInstance>>());
        x.set_neighbours(j.at("__neighbours").get<std::vector<nlohmann::json>>());
    }

    inline void to_json(json& j, const Level& x) {
        j = json::object();
        j["identifier"] = x.get_identifier();
        j["iid"] = x.get_iid();
        j["uid"] = x.get_uid();
        j["worldX"] = x.get_world_x();
        j["worldY"] = x.get_world_y();
        j["worldDepth"] = x.get_world_depth();
        j["pxWid"] = x.get_px_wid();
        j["pxHei"] = x.get_px_hei();
        j["__bgColor"] = x.get_bg_color();
        j["bgColor"] = x.get_level_bg_color();
        j["useAutoIdentifier"] = x.get_use_auto_identifier();
        j["bgRelPath"] = x.get_bg_rel_path();
        j["bgPos"] = x.get_level_bg_pos();
        j["bgPivotX"] = x.get_bg_pivot_x();
        j["bgPivotY"] = x.get_bg_pivot_y();
        j["__smartColor"] = x.get_smart_color();
        j["__bgPos"] = x.get_bg_pos();
        j["externalRelPath"] = x.get_external_rel_path();
        j["fieldInstances"] = x.get_field_instances();
        j["layerInstances"] = x.get_layer_instances();
        j["__neighbours"] = x.get_neighbours();
    }

    inline void from_json(const json& j, LdtkJson& x) {
        x.set_header(j.at("__header__").get<Header>());
        x.set_iid(j.at("iid").get<std::string>());
        x.set_json_version(j.at("jsonVersion").get<std::string>());
        x.set_app_build_id(j.at("appBuildId").get<int64_t>());
        x.set_next_uid(j.at("nextUid").get<int64_t>());
        x.set_identifier_style(j.at("identifierStyle").get<std::string>());
        x.set_toc(j.at("toc").get<std::vector<nlohmann::json>>());
        x.set_world_layout(j.at("worldLayout").get<std::string>());
        x.set_world_grid_width(j.at("worldGridWidth").get<int64_t>());
        x.set_world_grid_height(j.at("worldGridHeight").get<int64_t>());
        x.set_default_level_width(j.at("defaultLevelWidth").get<int64_t>());
        x.set_default_level_height(j.at("defaultLevelHeight").get<int64_t>());
        x.set_default_pivot_x(j.at("defaultPivotX").get<int64_t>());
        x.set_default_pivot_y(j.at("defaultPivotY").get<int64_t>());
        x.set_default_grid_size(j.at("defaultGridSize").get<int64_t>());
        x.set_default_entity_width(j.at("defaultEntityWidth").get<int64_t>());
        x.set_default_entity_height(j.at("defaultEntityHeight").get<int64_t>());
        x.set_bg_color(j.at("bgColor").get<std::string>());
        x.set_default_level_bg_color(j.at("defaultLevelBgColor").get<std::string>());
        x.set_minify_json(j.at("minifyJson").get<bool>());
        x.set_external_levels(j.at("externalLevels").get<bool>());
        x.set_export_tiled(j.at("exportTiled").get<bool>());
        x.set_simplified_export(j.at("simplifiedExport").get<bool>());
        x.set_image_export_mode(j.at("imageExportMode").get<ImageExportMode>());
        x.set_export_level_bg(j.at("exportLevelBg").get<bool>());
        x.set_png_file_pattern(get_untyped(j, "pngFilePattern"));
        x.set_backup_on_save(j.at("backupOnSave").get<bool>());
        x.set_backup_limit(j.at("backupLimit").get<int64_t>());
        x.set_backup_rel_path(get_untyped(j, "backupRelPath"));
        x.set_level_name_pattern(j.at("levelNamePattern").get<std::string>());
        x.set_tutorial_desc(j.at("tutorialDesc").get<std::string>());
        x.set_custom_commands(j.at("customCommands").get<std::vector<nlohmann::json>>());
        x.set_flags(j.at("flags").get<std::vector<std::string>>());
        x.set_defs(j.at("defs").get<Defs>());
        x.set_levels(j.at("levels").get<std::vector<Level>>());
        x.set_worlds(j.at("worlds").get<std::vector<nlohmann::json>>());
        x.set_dummy_world_iid(j.at("dummyWorldIid").get<std::string>());
    }

    inline void to_json(json& j, const LdtkJson& x) {
        j = json::object();
        j["__header__"] = x.get_header();
        j["iid"] = x.get_iid();
        j["jsonVersion"] = x.get_json_version();
        j["appBuildId"] = x.get_app_build_id();
        j["nextUid"] = x.get_next_uid();
        j["identifierStyle"] = x.get_identifier_style();
        j["toc"] = x.get_toc();
        j["worldLayout"] = x.get_world_layout();
        j["worldGridWidth"] = x.get_world_grid_width();
        j["worldGridHeight"] = x.get_world_grid_height();
        j["defaultLevelWidth"] = x.get_default_level_width();
        j["defaultLevelHeight"] = x.get_default_level_height();
        j["defaultPivotX"] = x.get_default_pivot_x();
        j["defaultPivotY"] = x.get_default_pivot_y();
        j["defaultGridSize"] = x.get_default_grid_size();
        j["defaultEntityWidth"] = x.get_default_entity_width();
        j["defaultEntityHeight"] = x.get_default_entity_height();
        j["bgColor"] = x.get_bg_color();
        j["defaultLevelBgColor"] = x.get_default_level_bg_color();
        j["minifyJson"] = x.get_minify_json();
        j["externalLevels"] = x.get_external_levels();
        j["exportTiled"] = x.get_export_tiled();
        j["simplifiedExport"] = x.get_simplified_export();
        j["imageExportMode"] = x.get_image_export_mode();
        j["exportLevelBg"] = x.get_export_level_bg();
        j["pngFilePattern"] = x.get_png_file_pattern();
        j["backupOnSave"] = x.get_backup_on_save();
        j["backupLimit"] = x.get_backup_limit();
        j["backupRelPath"] = x.get_backup_rel_path();
        j["levelNamePattern"] = x.get_level_name_pattern();
        j["tutorialDesc"] = x.get_tutorial_desc();
        j["customCommands"] = x.get_custom_commands();
        j["flags"] = x.get_flags();
        j["defs"] = x.get_defs();
        j["levels"] = x.get_levels();
        j["worlds"] = x.get_worlds();
        j["dummyWorldIid"] = x.get_dummy_world_iid();
    }

    inline void from_json(const json& j, ImageExportMode& x) {
        if (j == "None") x = ImageExportMode::NONE;
        else { throw std::runtime_error("Input JSON does not conform to schema!"); }
    }

    inline void to_json(json& j, const ImageExportMode& x) {
        switch (x) {
        case ImageExportMode::NONE: j = "None"; break;
        default: throw std::runtime_error("Unexpected value in enumeration \"ImageExportMode\": " + std::to_string(static_cast<int>(x)));
        }
    }

    inline void from_json(const json& j, TileMode& x) {
        if (j == "Single") x = TileMode::SINGLE;
        else { throw std::runtime_error("Input JSON does not conform to schema!"); }
    }

    inline void to_json(json& j, const TileMode& x) {
        switch (x) {
        case TileMode::SINGLE: j = "Single"; break;
        default: throw std::runtime_error("Unexpected value in enumeration \"TileMode\": " + std::to_string(static_cast<int>(x)));
        }
    }

    inline void from_json(const json& j, Mode& x) {
        if (j == "Random") x = Mode::RANDOM;
        else if (j == "Stamp") x = Mode::STAMP;
        else { throw std::runtime_error("Input JSON does not conform to schema!"); }
    }

    inline void to_json(json& j, const Mode& x) {
        switch (x) {
        case Mode::RANDOM: j = "Random"; break;
        case Mode::STAMP: j = "Stamp"; break;
        default: throw std::runtime_error("Unexpected value in enumeration \"Mode\": " + std::to_string(static_cast<int>(x)));
        }
    }
}
