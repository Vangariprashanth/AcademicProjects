using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

/**
* @author Abdelnasser Ouda
*
*/

namespace Sample_MVC
{
    static class Program
    {
        /// <summary>
        /// The main entry point  for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new View());
        }
    }
}
