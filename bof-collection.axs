var metadata = {
    name: "BOF-Collection",
    description: "Filesystem, process-control, and post-exploitation BOFs: type, mkdir, copy, move, del, rmdir, pwd, cd, ps, find-flags, exit, ...",
    nosave: true
};

var path = ax.script_dir();
ax.script_load(path + "FS-BOF/fs.axs");
ax.script_load(path + "Exit-BOF/exit.axs");
ax.script_load(path + "PS-BOF/ps.axs");
ax.script_load(path + "TK-BOF/tk.axs");
ax.script_load(path + "PostEx-BOF/postex.axs");
