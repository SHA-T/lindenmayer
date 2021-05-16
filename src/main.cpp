#include <filesystem>

#include "lindenmayersystem.h"

int main()
{
    std::filesystem::create_directory("results");

    LindenmayerSystem tree("Baum", 25, "++++F", {Production('F', "FF-[-F+F+F]+[+F-F]")});
    tree.generateSVGImages(1, 5);

    LindenmayerSystem dragon("Drachenkurve", 45, "L", {Production('R', "+R--L+"), Production('L', "-R++L-")});
    dragon.generateSVGImages(1, 15);

    LindenmayerSystem gosper("Gosper-Kurve", 60, "L", {Production('R', "R+L++L-R--RR-L+"), Production('L', "-R+LL++L+R--R-L")});
    gosper.generateSVGImages(1, 5);

    LindenmayerSystem hilbert("Hilbert-Kurve", 90, "X", {Production('X', "+YF-XFX-FY+"), Production('Y', "-XF+YFY+FX-")});
    hilbert.generateSVGImages(1, 7);

    LindenmayerSystem kochc("Koch-Kurve", 60, "F", {Production('F', "F+F--F+F")});
    kochc.generateSVGImages(1, 6);

    LindenmayerSystem kochf("Koch-Flocke", 60, "F--F--F", {Production('F', "F+F--F+F")});
    kochf.generateSVGImages(1, 6);

    LindenmayerSystem peano("Peano-Kurve", 90, "X", {Production('X', "XFYFX+F+YFXFY-F-XFYFX"), Production('Y', "YFXFY-F-XFYFX+F+YFXFY")});
    peano.generateSVGImages(1, 4);

    LindenmayerSystem cantor("Cantor-Diagonalisierung", 90, "F", {Production('F', "F-F+F+F+F-F-F-F+F")});
    cantor.generateSVGImages(1, 4);

    LindenmayerSystem plexity("Penta Plexity", 36, "F++F++F++F++F", {Production('F', "F++F++F|F-F++F")});
    plexity.generateSVGImages(1, 5);

    LindenmayerSystem arrow("Pfeilspitze", 60, "L", {Production('R', "-L+R+L-"), Production('L', "+R-L-R+")});
    arrow.generateSVGImages(1, 9);

    LindenmayerSystem sierpinski("Sierpinski-Dreieck", 60, "F++F++F", {Production('F', "F++F++F++ff"), Production('f', "ff")});
    sierpinski.generateSVGImages(1, 8);

    LindenmayerSystem carpet("Sierpinski-Teppich", 90, "F", {Production('F', "F+F-F-FF-F-F-fF"), Production('f', "fff")});
    carpet.generateSVGImages(1, 5);

    LindenmayerSystem levy("Lévy-C-Kurve", 45, "F", {Production('F', "+F--F+")});
    levy.generateSVGImages(1, 15);

    return 0;
}

