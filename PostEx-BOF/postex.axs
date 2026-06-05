var metadata = {
    name: "PostEx-BOF",
    description: "Post-exploitation BOFs: find-flags",
};

var cmd_find_flags = ax.create_command("find-flags", "Find common CTF flag files (e.g., user.txt, root.txt, flag.txt) across the filesystem", "find-flags");
cmd_find_flags.setPreHook(function (id, cmdline, parsed_json, ...parsed_lines) {
    let bof_path = ax.script_dir() + "_bin/find_flags." + ax.arch(id) + ".o";
    ax.execute_alias(id, cmdline, `execute bof "${bof_path}"`, "BOF: find-flags");
});

var group_postex = ax.create_commands_group("PostEx-BOF", [cmd_find_flags]);
ax.register_commands_group(group_postex, ["beacon", "gopher", "kharon"], ["windows"], []);
