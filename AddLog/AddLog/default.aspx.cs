using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Runtime.InteropServices;

namespace AddLog
{
    public partial class Default : System.Web.UI.Page
    {
        [DllImport("EventSource.dll", CharSet = CharSet.Unicode, EntryPoint = "NativeRegisterEventSource")]
        public static extern void NativeRegisterEventSource();

        protected void Page_Load(object sender, EventArgs e)
        {
            NativeRegisterEventSource();
        }

        [DllImport("EventSource.dll", CharSet = CharSet.Unicode, EntryPoint = "NativeReportEvent")]
        public static extern void NativeReportEvent();
        protected void Button1_Click(object sender, EventArgs e)
        {
            NativeReportEvent();
            Response.Write("Log has been add");
        }
    }
}