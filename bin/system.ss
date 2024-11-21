

// load plugin
load("libsq_system.so");

// local function
function prdir(f)
{
    print("calling prdi: " + f);
}

// main entry point, a[] is array of passed in params
function main(a)
{
    print("curent path =\n");
    print(current_path());

    print("curent path ls/\n");
    directory_iterator(prdir, "./");

    // call C class
    local bc = DerivedClass();
    local pbc = new_derived();

    print("base\n");
    pbc.functionbase();
    bc.functionbase();

    print("derived\n");
    pbc.functionderived();
    bc.functionderived()

    print("should delete intance\n");
    release_derived(pbc);

}
