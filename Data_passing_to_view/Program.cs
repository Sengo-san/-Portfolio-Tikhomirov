using _Data_passing_to_view.Models;

var builder = WebApplication.CreateBuilder();
builder.Services.AddControllersWithViews();
builder.Services.AddTransient<ICalcService, CalcService>();
var app = builder.Build();

app.UseStaticFiles();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();



public interface ICalcService
{
  CalcData data { get; }
}
public class CalcService : ICalcService
{    
    public CalcData data => new CalcData();
}