using Microsoft.AspNetCore.Mvc;

namespace _Data_passing_to_view.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
