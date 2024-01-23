#include "Modules.h"
#include <imgui.h>
#include "../Hook/JavaHook.h"

void Ripterms::Modules::Xray::renderGUI()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(20.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(250.0f, ImGui::GetStyle().FramePadding.y));
	ImGui::Checkbox("Xray (crash)", &enabled);
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();
}

void Ripterms::Modules::Xray::onShouldSideBeRendered(JNIEnv* env, Block& block, bool* cancel)
{
	if (!enabled) return;
	if (!block.instanceOf(Ripterms::JavaClassV2("net/minecraft/block/BlockOre").get_jclass(env)))
		Ripterms::JavaHook::set_return_value<uint64_t>(cancel, 0);
	else
		Ripterms::JavaHook::set_return_value<uint64_t>(cancel, 1);
	*cancel = true;
}
